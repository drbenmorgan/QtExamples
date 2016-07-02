# - Build the Qt Filesystem example
add_executable(qt-filesystem qt-filesystem.cpp)
target_link_libraries(qt-filesystem ${QT_CORE_LIBRARY})

# Copy filesystem style resources into build dir for testing
file(COPY bayeux config user DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Create resource "virtual" filesystem bundle
qt5_add_binary_resources(falaise falaise.qrc)
