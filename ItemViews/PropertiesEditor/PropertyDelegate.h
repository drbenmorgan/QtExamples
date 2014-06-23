// PropertyDelegate.h - delegate for property items
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

#ifndef PROPERTYDELEGATE_HH
#define PROPERTYDELEGATE_HH


#include <QItemDelegate>
#include <QComboBox>

class PropertyDelegate : public QItemDelegate {
  Q_OBJECT
 public:
  PropertyDelegate(QObject* parent = 0);
  virtual ~PropertyDelegate() {}

  QWidget* createEditor(QWidget* parent,
                        const QStyleOptionViewItem& option,
                        const QModelIndex &index) const;


  void setEditorData(QWidget *editor, const QModelIndex& index) const;
  void setModelData(QWidget *editor, QAbstractItemModel* model, const QModelIndex& index) const;
};

#endif // PROPERTYDELEGATE_HH

