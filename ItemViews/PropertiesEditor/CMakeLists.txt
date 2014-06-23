# - Build PropertiesEditor app
include_directories(${CMAKE_CURRENT_BINARY_DIR})

qt4_wrap_cpp(PROPERTIESEDITOR_MOC
  PropertiesEditor.h
  PropertiesModel.h
  PropertyDelegate.h
  )
qt4_wrap_ui(PROPERTIESEDITOR_UI
  PropertiesEditor.ui
  )

add_executable(PropertiesEditor ${PROPERTIESEDITOR_MOC} ${PROPERTIESEDITOR_UI} PropertiesEditor.cpp PropertiesModel.cpp PropertyDelegate.cpp main.cpp)
qt4_use_modules(PropertiesEditor Core Gui)

