set(TARGET_NAME server)

file(GLOB_RECURSE FILES *.c)

add_executable(${TARGET_NAME} ${FILES})

file(MAKE_DIRECTORY ${CURRENT_DIRECTORY}/${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CURRENT_DIRECTORY}/${TARGET_NAME})

include_directories(${PROJECT_SOURCE_DIR}/include/core)

target_link_libraries(${TARGET_NAME} core)
