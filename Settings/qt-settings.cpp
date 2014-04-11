// qt-settings- simple tests of QSettings etc
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

//
#include <sstream>

#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

#include <bayeux/datatools/properties.h>

Q_DECLARE_METATYPE(datatools::properties)
Q_DECLARE_METATYPE(datatools::properties::data)

struct IntSequence {
  int begin_;
  IntSequence() {begin_ = 0;}
  int operator()() {return ++begin_;}
};

bool readBayeuxSettings(QIODevice& device, QSettings::SettingsMap& map) {
  qDebug() << "called readBayeuxSettings";
  QByteArray bytes(device.readAll());
  std::string byteString(bytes.constData());
  std::istringstream byteStream(byteString);
  datatools::properties tmp;
  datatools::properties::config foo;
  foo.read(byteStream, tmp);

  // Fill Qt map, which will hold QString -> QVariant
  std::vector<std::string> keys = tmp.keys();
  std::vector<std::string>::iterator iter = keys.begin();
  std::vector<std::string>::iterator end = keys.end();

  for (; iter != end; ++iter) {
    // Does Qvariantizing work?
    QVariant v;
    v.setValue(tmp.get(*iter));
    map.insert(QString((*iter).c_str()), v);
  }

  return true;
}


bool writeBayeuxSettings(QIODevice& device, const QSettings::SettingsMap& map) {
  qDebug() << "called writeBayeuxSettings";

  // Iterate over map and convert here....
  // With QMetaization, should be able to copy in directly...
  datatools::properties tmp;
  QSettings::SettingsMap::const_iterator i = map.constBegin();
  while (i != map.constEnd()) {
    qDebug() << i.key();
    QVariant v = i.value();
    if (v.canConvert<datatools::properties::data>()) {
      datatools::properties::data d = v.value<datatools::properties::data>();
      tmp.store(i.key().toStdString(),d);
    }
    ++i;
  }

  tmp.tree_dump();
  std::ostringstream oput;
  datatools::properties::config foo;
  foo.write(oput, tmp);
  std::string oputStr = oput.str();
  QByteArray bytesOut(oputStr.data(), oputStr.size());
  device.write(bytesOut);

  return true;
}


int main(int argc, char *argv[]) {
  // Application
  QCoreApplication::setOrganizationName("SuperNEMO");
  QCoreApplication::setOrganizationDomain("nemo.org");
  QCoreApplication::setApplicationName("qt-settings");

  const QSettings::Format BayeuxFormat = QSettings::registerFormat("bayeux", readBayeuxSettings, writeBayeuxSettings);

  QSettings settings(BayeuxFormat,QSettings::UserScope,"SuperNEMO","qt-settings");

  //qDebug() << settings.value("foo/bar", "notread");

  settings.setValue("foo",1.23);

  return 0;
}
