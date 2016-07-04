# - Basic build script for Qt examples
#
cmake_minimum_required(VERSION 3.3)
project(QtExamples)

# Force C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# - Qt5, falling back to Qt4
find_package(Qt5 5.4 QUIET COMPONENTS Core Gui Widgets)

if(Qt5_FOUND)
  set(QT_VERSION_MAJOR 5)
  set(QT_CORE_LIBRARY Qt5::Core)
  set(QT_GUI_LIBRARY Qt5::Gui)
  set(QT_WIDGETS_LIBRARY Qt5::Widgets)
else()
  find_package(Qt4 4.8 REQUIRED QtCore QtGui)
  set(QT_CORE_LIBRARY Qt4::QtCore)
  set(QT_GUI_LIBRARY Qt4::QtGui)
endif()

add_subdirectory(Filesystem)
add_subdirectory(Settings)
add_subdirectory(ItemViews)
add_subdirectory(Plugins)
add_subdirectory(Flags)
