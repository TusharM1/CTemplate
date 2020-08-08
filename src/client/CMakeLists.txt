cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME client)

file(GLOB_RECURSE FILES *.c)

add_executable(${TARGET_NAME} ${FILES})

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${TARGET_NAME})

include_directories(${PROJECT_SOURCE_DIR}/include/core)

target_link_libraries(${TARGET_NAME} core)