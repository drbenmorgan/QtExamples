# - Build PropertiesEditor app
find_package(Boost 1.57 REQUIRED)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(AFTER ${Boost_INCLUDE_DIRS})

if(Qt5_FOUND)
  message(WARNING "ItemViews not yet working with Qt5\nWanrs about missing QItemDelegate header")
  return()
endif()

if(Qt5_FOUND)
qt5_wrap_cpp(PROPERTIESEDITOR_MOC
  PropertiesEditor.h
  PropertiesModel.h
  PropertyDelegate.h
  )
qt5_wrap_ui(PROPERTIESEDITOR_UI
  PropertiesEditor.ui
  )
else()
qt4_wrap_cpp(PROPERTIESEDITOR_MOC
  PropertiesEditor.h
  PropertiesModel.h
  PropertyDelegate.h
  )
qt4_wrap_ui(PROPERTIESEDITOR_UI
  PropertiesEditor.ui
  )
endif()

add_executable(PropertiesEditor ${PROPERTIESEDITOR_MOC} ${PROPERTIESEDITOR_UI} PropertiesEditor.cpp PropertiesModel.cpp PropertyDelegate.cpp main.cpp)
target_link_libraries(PropertiesEditor ${QT_CORE_LIBRARY} ${QT_GUI_LIBRARY} ${Qt_WIDGETS_LIBRARY})
