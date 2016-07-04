// qt-flags - simple tests of QFlags etc
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
#include <QFlags>
#include <QDebug>

namespace warwick {
// Appears that cannot use "testFlag" member function on implicit zero flags
// It will always return false...
enum class MyOption {Zero, Foo = 1, Bar, Baz};
Q_DECLARE_FLAGS(MyOptions, MyOption);
} // namespace warwick
Q_DECLARE_OPERATORS_FOR_FLAGS(warwick::MyOptions);

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  warwick::MyOptions a {warwick::MyOption::Foo};
  warwick::MyOptions b = warwick::MyOption::Bar;
  warwick::MyOptions cFromFlags = a | b;
  warwick::MyOptions cFromEnums = warwick::MyOption::Foo | warwick::MyOption::Bar;

  qDebug() << a << ", " << b << ", " << cFromFlags << cFromEnums;

  if ( cFromFlags.testFlag(warwick::MyOption::Foo) ) {
    qDebug() << "flag holds Foo entry";
  }
  if ( cFromFlags.testFlag(warwick::MyOption::Bar) ) {
    qDebug() << "flag holds Bar entry";
  }

  warwick::MyOptions None = warwick::MyOption::Zero;
  if (None) {
    qDebug() << "None flag is true";
  }

  if (b) {
    qDebug() << "Flag with non-zero equivalent is true";
  }


  if ( cFromFlags != cFromEnums ) {
    qDebug() << "options from flags are not the same as flags from enums";
  }

  return 0;
}

