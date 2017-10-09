### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Tue Jan 15 15:28:31 2013 (+0100)
## Version: $Id$
## Last-Updated: Mon Aug 26 15:17:04 2013 (+0200)
##           By: Julien Wintz
##     Update #: 25
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

project(tstCore)

######################################################################

## #################################################################
## Sources
## #################################################################

set(${PROJECT_NAME}_HEADERS
  tstPlugin.h
  tstPluginManager.h)

set(${PROJECT_NAME}_SOURCES
  tstPluginManager.cpp)

## #################################################################
## Build rules
## #################################################################

add_compiler_export_flags()

add_library(${PROJECT_NAME} SHARED
  ${${PROJECT_NAME}_SOURCES}
  ${${PROJECT_NAME}_HEADERS})

generate_export_header(${PROJECT_NAME}
     EXPORT_FILE_NAME "${PROJECT_NAME}Export.h")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}"
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export")

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Widgets)
