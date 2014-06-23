# - Build the Qt Settings example
# datatools/properties parsing needs Bayeux, so it's optional
find_package(Bayeux QUIET)
if(Bayeux_FOUND)
  include_directories(${Bayeux_INCLUDE_DIRS})
  add_executable(qt-settings qt-settings.cpp)
  target_link_libraries(qt-settings ${QT_QTCORE_LIBRARY} ${Bayeux_LIBRARIES})
endif()

add_executable(basic_settings basic_settings.cpp)
target_link_libraries(basic_settings ${QT_QTCORE_LIBRARY})
