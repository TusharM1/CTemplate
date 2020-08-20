# Minimum CMake Version
cmake_minimum_required(VERSION 3.15)

# Project Name and Version
project(Project
	VERSION 1.0.0
	DESCRIPTION "This is a C Project"
	LANGUAGES C)

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
include(ExternalProject)
set(UNITY unity)
ExternalProject_Add(
	${UNITY}
	GIT_REPOSITORY 		https://github.com/ThrowTheSwitch/Unity.git
	GIT_TAG 			v2.5.1
	PREFIX 				${PROJECT_SOURCE_DIR}/external/${UNITY}
	CONFIGURE_COMMAND 	cmake ../${UNITY}
	BUILD_COMMAND 		cmake --build .
	INSTALL_COMMAND 	cmake --install . --prefix ${PROJECT_SOURCE_DIR}
	UPDATE_COMMAND 		""
)
add_library(unity-library STATIC IMPORTED)
set_property(TARGET unity-library PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}unity${CMAKE_STATIC_LIBRARY_SUFFIX})
add_dependencies(unity-library unity)

# Enable testing and add testing folders
enable_testing()
add_subdirectory(tests)

# Generate documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
	add_custom_target(doxygen
		COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
		COMMAND make -C ${PROJECT_SOURCE_DIR}/doc/latex
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		COMMENT "Generating API documentation with Doxygen"
		VERBATIM)
else (DOXYGEN_FOUND)
	message("Doxygen needs to be installed to generate documentation")
endif (DOXYGEN_FOUND)
