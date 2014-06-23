// basic_settings - simple tests of QSettings etc
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
#include <QSettings>
#include <QDebug>
int main(int argc, char *argv[]) {
  // Application
  QCoreApplication::setOrganizationName("SuperNEMO");
  QCoreApplication::setOrganizationDomain("nemo.org");
  QCoreApplication::setApplicationName("basic_settings");

  QSettings settings;

  //qDebug() << settings.value("foo/bar", "notread");

  settings.setValue("foo",1.23);
  settings.setValue("foo/bar/baz", true);

  return 0;
}


