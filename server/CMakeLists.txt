# Set custom variable TARGET_NAME
set(TARGET_NAME server)

# Find all source and header files and set variable FILES to that
file(GLOB_RECURSE FILES *.c *.h)

# Add executable
add_executable(${TARGET_NAME} ${FILES})

# Link common library
target_link_libraries(${TARGET_NAME} common)

# Install executable
install(TARGETS ${TARGET_NAME} DESTINATION bin/${TARGET_NAME})
