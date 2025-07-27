cmake_minimum_required(VERSION 3.15)
project(TetrisTest)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)

include_directories(
    ${SRC_DIR}/libs
    ${SRC_DIR}/core
    ${SRC_DIR}/data
    ${SRC_DIR}/blocks
)

set(CATCH_SRC ${SRC_DIR}/libs/catch_amalgamated.cpp)

file(GLOB TEST_SOURCES
    "${SRC_DIR}/build/*.cpp"
)

foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)

    add_executable(${test_name}
        ${test_file}
        ${CATCH_SRC}
    )

    set_target_properties(${test_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${SRC_DIR}/test
    )
endforeach()
