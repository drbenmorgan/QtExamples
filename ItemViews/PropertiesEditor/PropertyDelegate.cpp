// PropertyDelegate.h - implementation
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

#include "PropertyDelegate.h"
#include <QDebug>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

// TODO : factorize the column numbers into an enum for clarity
//        move functionality of each column to map between column
//        number and function, i.e. isolate behaviour to allow, e.g.
//
//        return itemDelegateFor[index](args)

PropertyDelegate::PropertyDelegate(QObject* parent) : QItemDelegate(parent) {}

QWidget* PropertyDelegate::createEditor(QWidget* parent,
                                        const QStyleOptionViewItem& option,
                                        const QModelIndex& index) const {
  if (index.column() == 0) {
    // want a line edit with key validator
    QLineEdit *keyEditor = new QLineEdit(parent);
    QRegExp keyRegExp("[a-zA-Z]+[a-zA-Z0-9_]+");
    QRegExpValidator *keyValidator = new QRegExpValidator(keyRegExp, keyEditor);
    keyEditor->setValidator(keyValidator);
    return keyEditor;
  } else if (index.column() == 1) {
    QComboBox *typeEdit = new QComboBox(parent);
    QStringList typeNames;
    typeNames << "int"
              << "real"
              << "bool"
              << "string";
    typeEdit->insertItems(-1, typeNames);
    return typeEdit;
  } else if (index.column() == 2) {
    // Editor returned is dependent on model value in column 1
    const QAbstractItemModel* datum = index.model();
    QModelIndex indexToTypename = datum->index(index.row(), 1);
    QString value = datum->data(indexToTypename, Qt::DisplayRole).toString();
    if (value == "int") {
      return new QSpinBox(parent);
    } else if ( value == "real") {
      return new QDoubleSpinBox(parent);
    } else if (value == "bool") {
      return new QCheckBox(parent);
    }

    return QItemDelegate::createEditor(parent, option, index);
  } else {
    return QItemDelegate::createEditor(parent, option, index);
  }
}

void PropertyDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {
  // Populate with existing data, if present
  if (index.column() == 0) {
    QLineEdit *keyEditor = static_cast<QLineEdit*>(editor);
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    keyEditor->insert(value);
  }
  else if (index.column() == 1) {
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    int index = comboBox->findText(value);
    // Default to zeroth type
    index = index < 0 ? 0 : index;
    comboBox->setCurrentIndex(index);
    // NB: if the value in the combo box changes AFTER editting has
    // finished, then we must reset the value in the value column because
    // it will no longer be valid (type has changed).
  } else {
    QItemDelegate::setEditorData(editor, index);
  }
}

void PropertyDelegate::setModelData(QWidget *editor, QAbstractItemModel* model, const QModelIndex& index) const {
  if (index.column() == 1) {
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText();
    model->setData(index, value);
  } else {
    QItemDelegate::setModelData(editor, model, index);
  }
}

