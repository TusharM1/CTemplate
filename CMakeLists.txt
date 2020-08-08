cmake_minimum_required(VERSION 3.10)

project(Project VERSION 1.0)

file(MAKE_DIRECTORY bin)

add_subdirectory(src/core)

add_subdirectory(src/client)

add_subdirectory(src/server)