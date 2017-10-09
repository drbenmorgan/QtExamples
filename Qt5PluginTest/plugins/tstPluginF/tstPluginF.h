/* tstPluginF.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 15 16:52:52 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Aug 26 14:36:09 2013 (+0200)
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
#include "tstPluginFExport.h"

#include <QtCore>
#include <QtDebug>

class TSTPLUGINF_EXPORT tstPluginF : public tstPlugin {
  Q_INTERFACES(tstPlugin)
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "fr.inria.tstPlugin" FILE "tstPluginF.json")

 public:
  tstPluginF(void) {}
  ~tstPluginF(void) {}
};
