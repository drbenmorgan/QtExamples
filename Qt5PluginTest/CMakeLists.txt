### CMakeLists.txt ---
##
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Tue Jan 15 15:24:14 2013 (+0100)
## Version: $Id$
## Last-Updated: Mon Aug 26 14:19:57 2013 (+0200)
##           By: Julien Wintz
##     Update #: 20
######################################################################
##
### Commentary:
##
######################################################################
##
### Change log:
##
######################################################################

cmake_minimum_required(VERSION 3.3)

######################################################################

project(tst)

## #################################################################
##
## #################################################################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

## #################################################################
##
## #################################################################

mark_as_advanced(CMAKE_BUILD_TYPE)
mark_as_advanced(CMAKE_INSTALL_PREFIX)
mark_as_advanced(CMAKE_OSX_ARCHITECTURES)
mark_as_advanced(CMAKE_OSX_DEPLOYMENT_TARGET)
mark_as_advanced(CMAKE_OSX_SYSROOT)

## #################################################################
## Dependencies - Qt
## #################################################################

find_package(Qt5Core    REQUIRED)
find_package(Qt5Gui     REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## #################################################################
## Dependencies - internal
## #################################################################

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

## ###################################################################
##
## ###################################################################

include(GenerateExportHeader)

## #################################################################
## Input
## #################################################################

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(plugins)
