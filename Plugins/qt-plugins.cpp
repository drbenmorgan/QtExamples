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


int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  QStringList paths = QCoreApplication::libraryPaths();

  Q_FOREACH(const QString& s, paths) {
    qDebug() << s;
  }

  return 0;
}
