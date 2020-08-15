# Minimum CMake Version
cmake_minimum_required(VERSION 3.15)

# Project Name and Version
project(Project VERSION 1.0.0)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Werror -Wpedantic)
endif()

# Set Install Location
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# Add core library
add_subdirectory(common)

# Add client module
add_subdirectory(client)

# Add server module
add_subdirectory(server)

# Add testing framework
# set(CMAKE_CXX_STANDARD 17)
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        release-1.10.0
# )
# FetchContent_MakeAvailable(googletest)
# FetchContent_GetProperties(googletest)
# if(NOT googletest_POPULATED)
#   FetchContent_Populate(googletest)
#   add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
# endif()
# enable_testing()
# add_subdirectory(tests)

# Testing Attempt 2
enable_testing()
add_subdirectory(tests)

# Generate documentation
# find_package(Doxygen)
# if (DOXYGEN_FOUND)
# 	add_custom_target(doc_doxygen ALL
# 		COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
# 		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
# 		COMMENT "Generating API documentation with Doxygen"
# 		VERBATIM)
# else (DOXYGEN_FOUND)
# 	message("Doxygen needs to be installed to generate documentation")
# endif (DOXYGEN_FOUND)
