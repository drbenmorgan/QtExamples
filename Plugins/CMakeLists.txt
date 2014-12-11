# - Build the Qt Plugins example
add_executable(qt-plugins qt-plugins.cpp)
target_link_libraries(qt-plugins ${QT_QTCORE_LIBRARY})
