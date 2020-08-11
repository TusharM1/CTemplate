# Set custom variable TARGET_NAME
set(TARGET_NAME server)

# Find all source and header files and set variable FILES to that
file(GLOB_RECURSE FILES *.c *.h)

# Add executable
add_executable(${TARGET_NAME} ${FILES})

# Include core library interface
include_directories(${PROJECT_SOURCE_DIR}/core/include)

# Link core library
target_link_libraries(${TARGET_NAME} core)

install(TARGETS ${TARGET_NAME} DESTINATION bin/${TARGET_NAME})
