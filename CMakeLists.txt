# Minimum CMake Version
cmake_minimum_required(VERSION 3.15)

# Project Name and Version
project(Project VERSION 1.0.0)

# Compile with warnings
if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Werror -Wpedantic)
endif()

# Set Install Location
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# Set include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add core library
add_subdirectory(common)

# Add client module
add_subdirectory(client)

# Add server module
add_subdirectory(server)

# Add Unity testing framework from github
include(FetchContent)
FetchContent_Declare(
	unity
	GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
	GIT_TAG        v2.5.1
)
FetchContent_MakeAvailable(unity)
FetchContent_GetProperties(unity)
if(NOT unity_POPULATED)
	FetchContent_Populate(unity)
	add_subdirectory(${unity_SOURCE_DIR} ${unity_BINARY_DIR})
endif()

# Enable testing and add testing folders
enable_testing()
add_subdirectory(tests)

# Generate documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
	add_custom_target(doxygen
		COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		COMMENT "Generating API documentation with Doxygen"
		VERBATIM)
else (DOXYGEN_FOUND)
	message("Doxygen needs to be installed to generate documentation")
endif (DOXYGEN_FOUND)
