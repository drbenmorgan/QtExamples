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

#include <QDir>
#include <QDebug>

int main(int argc, char *argv[]) {

  // Get list of search paths for null prefix
  QStringList searchPaths(QDir::searchPaths("/"));

  Q_FOREACH(const QString& p, searchPaths)
      qDebug() << p;

  // Add a search path
  QDir::setSearchPaths("falaise", QStringList(QDir::homePath() + "/.falaise"));

  searchPaths = QDir::searchPaths("falaise");

  Q_FOREACH(const QString& p, searchPaths)
      qDebug() << p;


  return 0;
}
