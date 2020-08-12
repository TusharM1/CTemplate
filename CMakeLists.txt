# Minimum CMake Version
cmake_minimum_required(VERSION 3.15)

# Project Name and Version
project(Project VERSION 1.0.0)

# Set Install Location
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# Add core library
add_subdirectory(common)

# Add client module
add_subdirectory(client)

# Add server module
add_subdirectory(server)

# Generate documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
	add_custom_target(doc_doxygen ALL 
		COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		COMMENT "Generating API documentation with Doxygen"
		VERBATIM)
else (DOXYGEN_FOUND)
	message("Doxygen needs to be installed to generate documentation")
endif (DOXYGEN_FOUND)
