// PropertiesModel.h - wrapper around basic "properties" data structure
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

#ifndef PROPERTIESMODEL_H
#define PROPERTIESMODEL_H

#include <QAbstractTableModel>
#include <QString>

#include <vector>
#include <boost/array.hpp>

class PropertiesModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    PropertiesModel(QObject *parent);

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    bool insertRows(int position, int rows, const QModelIndex& index);

public slots:
    void appendRow();

private:
    typedef boost::array<QString,3> RowType;
    std::vector<RowType> gridmodel;
};

#endif // PROPERTIESMODEL_H
