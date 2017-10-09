/* tstPluginD.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 15 16:52:52 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Aug 26 14:28:03 2013 (+0200)
 *           By: Julien Wintz
 *     Update #: 45
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <tstCore/tstPlugin.h>
#include "tstPluginDExport.h"

#include <QtCore>
#include <QtDebug>

class TSTPLUGIND_EXPORT tstPluginD : public tstPlugin {
  Q_INTERFACES(tstPlugin)
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "fr.inria.tstPlugin" FILE "tstPluginD.json")

 public:
  tstPluginD(void) {}
  ~tstPluginD(void) {}
};
