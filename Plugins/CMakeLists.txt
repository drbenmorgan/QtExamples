# - Build the Qt Plugins example
add_executable(qt-plugins qt-plugins.cpp)
target_link_libraries(qt-plugins ${QT_CORE_LIBRARY})

#add_definitions(-DQT_PLUGIN)
include_directories(${CMAKE_CURRENT_LIST_DIR})
add_library(echoplugin SHARED
  echoplugin.h
  echoplugin.cpp
  echoplugin.json
  )

# NB, plugins must be moc'd!!
set_target_properties(echoplugin PROPERTIES AUTOMOC ON)
qt5_use_modules(echoplugin Core)
qt5_use_modules(echoplugin Gui)
qt5_use_modules(echoplugin Widgets)
