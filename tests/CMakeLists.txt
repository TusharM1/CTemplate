# Set custom variable TARGET_NAME
set(TARGET_NAME tester)

# Find all source and header files and set variable FILES to that
file(GLOB_RECURSE FILES *.c *.h)

# Add executable
add_executable(${TARGET_NAME} ${FILES})

# Link libraries
target_link_libraries(${TARGET_NAME} PUBLIC unity common)

# Add tests to list
add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
