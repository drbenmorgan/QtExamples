// PropertiesModel.cpp - Implementation
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

#include "PropertiesModel.h"
#include <QDebug>

PropertiesModel::PropertiesModel(QObject *parent)
    :QAbstractTableModel(parent)
{
  // Create dumb initial data
  RowType dummy = {{"foo", "bar", "baz"}};
  gridmodel.push_back(dummy);
}

int PropertiesModel::rowCount(const QModelIndex & /*parent*/) const
{
    return gridmodel.size();
}

int PropertiesModel::columnCount(const QModelIndex & /*parent*/) const
{
    return RowType::static_size;
}

QVariant PropertiesModel::data(const QModelIndex &index, int role) const
{
  qDebug() << QString("row %1, col %2, role %3").arg(index.row()).arg(index.column()).arg(role);

    if (role == Qt::DisplayRole)
    {
        return gridmodel[index.row()][index.column()];
    }
    return QVariant();
}

bool PropertiesModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
  if (role == Qt::EditRole)
  {
    //save value from editor to internal model
    gridmodel[index.row()][index.column()] = value.toString();
    emit(dataChanged(index, index));
  }
  return true;
}

Qt::ItemFlags PropertiesModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

//set horizontal headers only!
QVariant PropertiesModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      switch (section) {
        case 0:
          return QString("key");
        case 1:
          return QString("type");
        case 2:
          return QString("value");
      }
    }
  }
  return QVariant();
}


// Insert rows
bool PropertiesModel::insertRows(int position, int rows, const QModelIndex& index) {

  // Useful little macro that can be used instead of commenting out
  // the argument name
  Q_UNUSED(index);

  // Must begin...
  beginInsertRows(QModelIndex(), position, position+rows-1);

  RowType dummy = {{"<null>", "int", "0"}};
  gridmodel.insert(gridmodel.begin()+position, rows, dummy);

  // Must end...
  endInsertRows();
  return true;
}

void PropertiesModel::appendRow() {
  this->insertRows(gridmodel.size(),1,QModelIndex());

}

