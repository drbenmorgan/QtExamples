// qt-filesystem - simple tests of QDir etc
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
#include <QDir>
#include <QResource>
#include <QDebug>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  qDebug() << "Default application library paths:";
  Q_FOREACH(const QString& p, app.libraryPaths())
      qDebug() << p;

  // Load the default resource bundle
  QResource::registerResource(QCoreApplication::applicationDirPath() + "/falaise.rcc");

  // Add Search paths for "falaise" prefix
  // The order affects (later) how files are located. Consider it a layered
  // configuration/
  QDir::setSearchPaths("falaise",
                       QStringList() << ":/falaise"
                                     << QCoreApplication::applicationDirPath() + "/config"
                                     << QCoreApplication::applicationDirPath() + "/user"
                       );
  // Add search paths for "bayeux" prefix. This means we can have identical
  // filenames, but reoslved differently according to prefix.
  QDir::setSearchPaths("bayeux",
                       QStringList() << QCoreApplication::applicationDirPath() + "/bayeux"
                       );


  qDebug() << "Default file search paths for 'falaise' prefix:";

  Q_FOREACH(const QString& p, QDir::searchPaths("falaise"))
      qDebug() << p;

  // See how files are resolved
  QString configFilename("config.conf");

  // In Falaise, it should be the one in config
  qDebug() << "Which falaise config file is found first?:";
  QFile falaiseConfig("falaise:" + configFilename);
  if(falaiseConfig.exists()) {
    falaiseConfig.open(QIODevice::ReadOnly);
    QTextStream in(&falaiseConfig);
    qDebug() << falaiseConfig.fileName() << ": " << in.readLine();
  }

  // Now qualify with bayeux prefix
  qDebug() << "Is Bayeux config file resolved?:";
  QFile bayeuxConfig("bayeux:" + configFilename);
  if(bayeuxConfig.exists()) {
    bayeuxConfig.open(QIODevice::ReadOnly);
    QTextStream in(&bayeuxConfig);
    qDebug() << bayeuxConfig.fileName() << ": " << in.readLine();
  }

  return 0;
}
