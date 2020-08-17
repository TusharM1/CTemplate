# Set custom variable TARGET_NAME
set(TARGET_NAME common)

# Find all source and header files and set variable FILES to that
file(GLOB_RECURSE FILES *.c *.h)

# Add static library
add_library(${TARGET_NAME} STATIC ${FILES})

# Install library
install(TARGETS ${TARGET_NAME} DESTINATION lib/)
