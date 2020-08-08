cmake_minimum_required(VERSION 3.10)

project(Project VERSION 1.0)

get_filename_component(CONFIGURATION_NAME ${CMAKE_BINARY_DIR} NAME)

set(CURRENT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${CONFIGURATION_NAME})

file(MAKE_DIRECTORY bin)

add_subdirectory(src/core)

add_subdirectory(src/client)

add_subdirectory(src/server)
