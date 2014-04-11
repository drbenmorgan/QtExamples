# - Basic build script for Qt examples
#
cmake_minimum_required(VERSION 2.8.10)
project(QtExamples)

# - Qt4 only for now
# TODO : Qt5 support, plus checks on history of FindQt4 interface (linked
# to which minimum CMake version to support).
find_package(Qt4 REQUIRED QtCore)
include(${QT_USE_FILE})

add_subdirectory(Filesystem)
add_subdirectory(Settings)

