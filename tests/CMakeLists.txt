# Set custom variable TARGET_NAME
set(TARGET_NAME tester)

# Find all source and header files and set variable FILES to that
#file(GLOB_RECURSE FILES *.cpp *.h)

# Add executable
add_executable(${TARGET_NAME} tester.c)
# add_executable(${TARGET_NAME} ${FILES})
# add_executable(COMMANDS_TEST commands_test.cpp)
# add_executable(STRINGS_TEST strings_test.cpp)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/common/include)

# Link libraries
# target_link_libraries(${TARGET_NAME} PUBLIC gtest_main common)
target_link_libraries(${TARGET_NAME} PUBLIC common)
# target_link_libraries(COMMANDS_TEST PUBLIC common)
# target_link_libraries(STRINGS_TEST PUBLIC common)

# Add tests to list
add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
# add_test(COMMANDS_TEST COMMANDS_TEST)
# add_test(STRINGS_TEST STRINGS_TEST)
