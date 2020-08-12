# Set custom variable TARGET_NAME
set(TARGET_NAME client)

# Find all source and header files and set variable FILES to that
file(GLOB_RECURSE FILES *.c *.h)

# Add executable
add_executable(${TARGET_NAME} ${FILES})

# Include common library interface
include_directories(${PROJECT_SOURCE_DIR}/common/include)

# Link common library
target_link_libraries(${TARGET_NAME} common)

install(TARGETS ${TARGET_NAME} DESTINATION _bin/${TARGET_NAME})
