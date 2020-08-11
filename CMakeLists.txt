# Minimum CMake Version
cmake_minimum_required(VERSION 3.15)

# Project Name and Version
project(Project VERSION 1.0.0)

# Set Install Location
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# Add core library
add_subdirectory(core)

# Add client module
add_subdirectory(client)

# Add server module
add_subdirectory(server)
