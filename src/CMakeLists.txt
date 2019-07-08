# list all source files in "."
AUX_SOURCE_DIRECTORY(. SRC_LIST)
# build source to bin
ADD_EXECUTABLE(main ${SRC_LIST})
# add the header search path
TARGET_INCLUDE_DIRECTORIES(main PUBLIC ${PROJECT_SOURCE_DIR}/include)
# add include dependency
TARGET_LINK_LIBRARIES(main PUBLIC add)

# install main executable to ${CMAKE_INSTALL_PREFIX}/bin
install(TARGETS main
    RUNTIME DESTINATION bin)

MESSAGE("test/src CMAKE_CURRENT_SOURCE_DIR " ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("test/src PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
MESSAGE("test/src PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})