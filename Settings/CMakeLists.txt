# - Build the Qt Settings example
# datatools/properties parsing needs Bayeux, so it's optional
find_package(Bayeux QUIET)
if(Bayeux_FOUND)
  include_directories(${Bayeux_INCLUDE_DIRS})
  add_executable(qt-settings qt-settings.cpp)
  target_link_libraries(qt-settings ${QT_QTCORE_LIBRARY} ${Bayeux_LIBRARIES})
endif()

