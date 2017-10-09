/* tstPlugin.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 15 16:18:30 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Aug 26 15:15:07 2013 (+0200)
 *           By: Julien Wintz
 *     Update #: 41
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include "tstCoreExport.h"

#include <QtCore/QObject>

class TSTCORE_EXPORT tstPlugin : public QObject {
  Q_OBJECT

 public:
  tstPlugin(void) {}
  virtual ~tstPlugin(void) {}
};

Q_DECLARE_INTERFACE(tstPlugin, "fr.inria.tstPlugin")
