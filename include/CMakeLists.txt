# build shared library
add_library(add SHARED add.cpp)
# set the version for shared library
SET_TARGET_PROPERTIES(add PROPERTIES VERSION 1.2 SOVERSION 1)

#build static library
add_library(add_static STATIC add.cpp)

# install the shared library ${CMAKE_INSTALL_PREFIX}/include
install(TARGETS add
    LIBRARY DESTINATION include)

# install the static library ${CMAKE_INSTALL_PREFIX}/include
install(TARGETS add_static
    ARCHIVE DESTINATION include)

MESSAGE("test/include CMAKE_CURRENT_SOURCE_DIR " ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("test/include project source dir " ${PROJECT_SOURCE_DIR})
MESSAGE("test/include PROJECT_SOURCE_DIR " ${PROJECT_BINARY_DIR})