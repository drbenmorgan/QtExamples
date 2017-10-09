/* tstPluginManager.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 15 16:25:00 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 15 23:17:20 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 280
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "tstPluginManager.h"
#include "tstPlugin.h"

#include <QtCore>
#include <QtDebug>

static void recordDelete(QPluginLoader* obj) {
  qDebug() << "deleting " << obj;
  delete obj;
}

// /////////////////////////////////////////////////////////////////
// tstPluginManagerPrivate
// /////////////////////////////////////////////////////////////////

class tstPluginManager::tstPluginManagerPrivate {
 public:
  bool check(const QString& path);

 public:
  QHash<QString, QVariant> names;
  QHash<QString, QVariant> versions;
  QHash<QString, QVariantList> dependencies;
  QHash<QString, QSharedPointer<QPluginLoader>> loaders;
};

bool tstPluginManager::tstPluginManagerPrivate::check(const QString& path) {
  bool status = true;
  qDebug() << "  check() called with " << path;

  for (auto& item : this->dependencies.value(path)) {
    QVariantMap mitem = item.toMap();
    QVariant na_mitem = mitem.value("name");
    QVariant ve_mitem = mitem.value("version");
    QString key = this->names.key(na_mitem);

    if (!this->names.values().contains(na_mitem)) {
      // qDebug() << Q_FUNC_INFO << "  Missing dependency:" <<
      // na_mitem.toString()
      //       << "for plugin" << path;
      status = false;
      continue;
    }

    if (this->versions.value(key) != ve_mitem) {
      // qDebug() << Q_FUNC_INFO << "    Version mismatch:" <<
      // na_mitem.toString()
      //       << "version"
      //     << this->versions.value(this->names.key(na_mitem)).toString()
      //   << "but" << ve_mitem.toString() << "required for plugin" << path;
      status = false;
      continue;
    }

    if (!check(key)) {
      // qDebug() << Q_FUNC_INFO << "Corrupted dependency:" <<
      // na_mitem.toString()
      //        << "for plugin" << path;
      status = false;
      continue;
    }
  }

  return status;
}

// /////////////////////////////////////////////////////////////////
// tstPluginManager
// /////////////////////////////////////////////////////////////////
tstPluginManager::tstPluginManager() : d{new tstPluginManagerPrivate} {}

tstPluginManager::~tstPluginManager() {}

tstPluginManager* tstPluginManager::instance() {
  static tstPluginManager s_instance;
  return &s_instance;
}

void tstPluginManager::initialize() {
  QDir path = QDir(qApp->applicationDirPath());
  path.cdUp();
  path.cd("plugins");

  qDebug() << Q_FUNC_INFO << "called";

  // This tries to load metadata from every file in the plugin path
  // TODO: allow additions to path via setting (env or script)
  for (QFileInfo& info :
       path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)) {
    qDebug() << "calling scan() with " << info.absoluteFilePath();
    this->scan(info.absoluteFilePath());
  }

  qDebug() << " After scanning, hashes are:";
  qDebug() << " d->names:";
  for (auto& iter : d->names.keys()) {
    qDebug() << " " << iter << ", " << d->names.value(iter);
  }
  qDebug() << " d->versions:";
  for (auto& iter : d->versions.keys()) {
    qDebug() << " " << iter << ", " << d->versions.value(iter);
  }
  qDebug() << " d->dependencies:";
  for (auto& iter : d->dependencies.keys()) {
    qDebug() << " " << iter << ", " << d->dependencies.value(iter);
  }

  // Now loads every file in the plugin path
  // TODO: Make it selective based on set of modules?
  // TODO: What about concurrent versions of same module?
  //       E,g,, could distringuish by name "libX-1.0.0.so" but
  //       could symbols clash if two versions are loaded?

  for (QFileInfo& info :
       path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)) {
    qDebug() << "calling load() with " << info.absoluteFilePath();
    this->load(info.absoluteFilePath());
  }
}

void tstPluginManager::uninitialize(void) {
  for (const QString& path : d->loaders.keys()) {
    this->unload(path);
  }
}

void tstPluginManager::scan(const QString& path) {
  // Effectively a preload step, just get and store metadata
  if (!QLibrary::isLibrary(path)) return;

  QScopedPointer<QPluginLoader> loader{new QPluginLoader(path)};

  d->names.insert(path, loader->metaData()
                            .value("MetaData")
                            .toObject()
                            .value("name")
                            .toVariant());
  d->versions.insert(path, loader->metaData()
                               .value("MetaData")
                               .toObject()
                               .value("version")
                               .toVariant());
  d->dependencies.insert(path, loader->metaData()
                                   .value("MetaData")
                                   .toObject()
                                   .value("dependencies")
                                   .toArray()
                                   .toVariantList());
}

void tstPluginManager::load(const QString& path) {
  // Actually loads the library
  if (!QLibrary::isLibrary(path) || !d->check(path)) {
    return;
  }

  // Custom deleter just to check that delete happens
  // Apparently, can't store QScopedPointer (or std::unique_ptr) in
  // Qt collections. Use a shared pointer instead - non-optimal
  // but loaders are local to this object and simplifies memory management.
  QSharedPointer<QPluginLoader> loader{new QPluginLoader(path), recordDelete};

  if (tstPlugin* plugin = qobject_cast<tstPlugin*>(loader->instance())) {
    d->loaders.insert(path, loader);
  }
}

void tstPluginManager::unload(const QString& path) {
  qDebug() << "unload() called with " << path;
  auto loader = d->loaders.value(path);

  if (loader->unload()) {
    d->loaders.remove(path);
  }
}

QStringList tstPluginManager::plugins() { return d->loaders.keys(); }
