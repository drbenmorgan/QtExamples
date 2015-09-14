// qt-plugins - simple tests of QPluginLoader etc
//
// Copyright (c) 2014 by Ben Morgan <bmorgan.warwick@gmail.com>
// Copyright (c) 2014 by The University of Warwick
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QString>

#include <QDir>

#include <QPluginLoader>

#include <iostream>

#include "echointerface.h"

// Static plugins here via Q_IMPORT_PLUGIN
// See http://doc.qt.io/qt-5/qtwidgets-tools-plugandpaint-example.html


int main(int argc, char *argv[]) {
  // Must have a QCoreApplication before we can load plugins
  QCoreApplication app(argc, argv);

  // Library/plugin search paths
  QStringList paths = app.libraryPaths();

  Q_FOREACH(const QString& s, paths) {
    qDebug() << s;
  }

  // For an unknown reason, this will not work with Qt4 - the search
  // patth defined by QCoreApplication::libraryPaths does not seem to
  // be respected, so the plugin can only be loaded if the application is
  // run from the same directory as the plugin.
  // seems fine on Qt5.
  QPluginLoader dumpPlugin("libechoplugin.dylib");
  std::cout << "DumpModule file   : " << dumpPlugin.fileName().toStdString() << std::endl;
  dumpPlugin.load();
  std::cout << "DumpModule error  : " << dumpPlugin.errorString().toStdString() << std::endl;
  std::cout << "DumpModule file   : " << dumpPlugin.fileName().toStdString() << std::endl;
  std::cout << "DumpModule loaded : " << dumpPlugin.isLoaded() << std::endl;

  std::cout << "DumpModule instance : " << dumpPlugin.instance() << std::endl;


  return 0;
}
