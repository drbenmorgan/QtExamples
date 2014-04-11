# - Build the Qt Filesystem example
add_executable(qt-filesystem qt-filesystem.cpp)
target_link_libraries(qt-filesystem ${QT_QTCORE_LIBRARY})
