# Set custom variable TARGET_NAME
set(TARGET_NAME core)

# Find all source and header files and set variable FILES to that
file(GLOB_RECURSE FILES *.c)

# Add static library
add_library(${TARGET_NAME} STATIC ${FILES})

# Make directory of name in binary folder
#file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/${TARGET_NAME})

# Set the output directory to the binary folder
#set_target_properties(${TARGET_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/${TARGET_NAME})