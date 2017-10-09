/* main.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 15 16:15:32 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 15 23:14:28 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 27
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include <QtCore>
#include <QtDebug>

#include <tstCore/tstPlugin.h>
#include <tstCore/tstPluginManager.h>

int main(int argc, char **argv) {
  QCoreApplication application(argc, argv);

  tstPluginManager::instance()->initialize();

  qDebug() << "\nSuccessfully loaded:"
           << tstPluginManager::instance()->plugins();

  tstPluginManager::instance()->uninitialize();

  return 0;
}
