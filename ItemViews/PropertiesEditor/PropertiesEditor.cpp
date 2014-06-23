// PropertiesEditor.cpp - implementation
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


#include "PropertiesEditor.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include "PropertiesModel.h"
#include "PropertyDelegate.h"

PropertiesEditor::PropertiesEditor(QWidget* parent) : QMainWindow(parent) {
  ui.setupUi(this);
  PropertiesModel* pModel = new PropertiesModel(this);
  // By hand...
  ui.propertyTableView->setModel(pModel);
  ui.propertyTableView->setItemDelegate(new PropertyDelegate());
  ui.propertyTableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

void PropertiesEditor::on_action_Open_triggered() {
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open File"),
                                                  "",
                                                  tr("*.txt"));
  if(!fileName.isEmpty()) {
    qDebug() << "You selected: " << fileName;
  }
}

void PropertiesEditor::on_action_About_Properties_triggered() {
  QMessageBox::about(this,
                     "About PropertiesEditor",
                     "An editor for LPC properties files");
}

void PropertiesEditor::on_action_Properties_Help_triggered() {
  QMessageBox::warning(this,
                       "NOTIMPLEMENTED",
                       "Will display help on properties grammar\nand using this application");
}

void PropertiesEditor::on_newProperty_clicked() {
  QMessageBox::warning(this,
                       "NOTIMPLEMENTED",
                       "Will add a row to the properties list");
}

void PropertiesEditor::on_deleteProperty_clicked() {
  QMessageBox::warning(this,
                       "NOTIMPLEMENTED",
                       "Will delete selected rows from the properties list");
}

