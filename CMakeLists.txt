# set the minimum version for cmake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

# set the project name
PROJECT(workspace)
# set c++11 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -O0 -g -rdynamic -fopenmp")
# set print warning info
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
# directive to print detail build log
SET(CMAKE_VERBOSE_MAKEFILE OFF)
# set the install prefix for make install
SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install CACHE PATH "" FORCE)
# set the output directory for bin during building(make)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tmp/bin)
# set the output directory for libs during building(make)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tmp/lib)

# include and build  submodule build configuration
ADD_SUBDIRECTORY(src)

# include and build the libs submodule
ADD_SUBDIRECTORY(include)

# include and build the test submodule
ADD_SUBDIRECTORY(test)

# add test target
ENABLE_TESTING()
ADD_TEST(UTTest ${PROJECT_BINARY_DIR}/tmp/bin/TestCase)

# install directory to target directory ${CMAKE_INSTALL_PREFIX}/.
# INSTALL(DIRECTORY docs DESTINATION .)

# install files to target directory ${CMAKE_INSTALL_PREFIX}/.
INSTALL(FILES COPYRIGHT DESTINATION .)

# current directory of CMakeLists.txt
MESSAGE("test CMAKE_CURRENT_SOURCE_DIR " ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("test CMAKE_CURRRENT_BINARY_DIR " ${CMAKE_CURRRENT_BINARY_DIR})
MESSAGE("test PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
MESSAGE("test PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})
MESSAGE("test CMAKE_INSTALL_PREFIX " ${CMAKE_INSTALL_PREFIX})

# environment variable
MESSAGE("test CMAKE_INCLUDE_PATH " $ENV{CMAKE_INCLUDE_PATH})
MESSAGE("test CMAKE_LIBRARY_PATH " $ENV{CMAKE_LIBRARY_PATH})