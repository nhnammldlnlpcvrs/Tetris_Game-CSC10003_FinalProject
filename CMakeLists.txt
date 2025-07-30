cmake_minimum_required(VERSION 3.15)
project(TetrisTest)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/nghoo/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)

include_directories(
    ${SRC_DIR}/libs
    ${SRC_DIR}/core
    ${SRC_DIR}/data
    ${SRC_DIR}/blocks
)

set(CATCH_SRC ${SRC_DIR}/libs/catch_amalgamated.cpp)

file(GLOB_RECURSE CORE_SOURCES
    "${SRC_DIR}/core/*.cpp"
    "${SRC_DIR}/data/*.cpp"
    "${SRC_DIR}/blocks/*.cpp"
)

file(GLOB TEST_SOURCES
    "${SRC_DIR}/build/*.cpp"
)

list(REMOVE_ITEM TEST_SOURCES "${SRC_DIR}/build/test_move.cpp")

find_package(raylib CONFIG REQUIRED)

foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)

    add_executable(${test_name}
        ${test_file}
        ${CATCH_SRC}
        ${CORE_SOURCES}
    )

    set_target_properties(${test_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${SRC_DIR}/test
    )

    target_link_libraries(${test_name} PRIVATE raylib)
endforeach()

add_executable(test_move
    ${SRC_DIR}/build/test_move.cpp
    ${CORE_SOURCES}
)

set_target_properties(test_move PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${SRC_DIR}/test
)

target_link_libraries(test_move PRIVATE raylib)
