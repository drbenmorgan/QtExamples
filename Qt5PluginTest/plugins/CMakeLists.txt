### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Tue Jan 15 16:50:43 2013 (+0100)
## Version: $Id$
## Last-Updated: Tue Jan 15 23:41:13 2013 (+0100)
##           By: Julien Wintz
##     Update #: 6
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

add_subdirectory(tstPluginA)
add_subdirectory(tstPluginB)
add_subdirectory(tstPluginC)
add_subdirectory(tstPluginD)

if(WITH-E-1)
add_subdirectory(tstPluginE-0.0.1)
endif(WITH-E-1)

if(WITH-E-2)
add_subdirectory(tstPluginE-0.0.2)
endif(WITH-E-2)

add_subdirectory(tstPluginF)
