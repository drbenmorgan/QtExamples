/* tstPluginManager.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 15 16:22:48 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Aug 26 15:15:53 2013 (+0200)
 *           By: Julien Wintz
 *     Update #: 37
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include "tstCoreExport.h"

#include <QtCore/QObject>
#include <QtCore/QScopedPointer>

class TSTCORE_EXPORT tstPluginManager : public QObject {
  Q_OBJECT
 public:
  static tstPluginManager* instance(void);

  void initialize();
  void uninitialize();
  void scan(const QString& path);
  void load(const QString& path);
  void unload(const QString& path);

  QStringList plugins(void);

 private:
  tstPluginManager();
  ~tstPluginManager();

 private:
  class tstPluginManagerPrivate;
  QScopedPointer<tstPluginManagerPrivate> d;
};
