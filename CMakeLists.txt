cmake_minimum_required(VERSION 3.15)
project(TetrisTest)

set(CMAKE_CXX_STANDARD 17)

# Gọi pkg-config để lấy thông tin raylib
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

include_directories(${RAYLIB_INCLUDE_DIRS})
link_directories(${RAYLIB_LIBRARY_DIRS})

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)

# Include local project headers
include_directories(
    ${SRC_DIR}/libs
    ${SRC_DIR}/core
    ${SRC_DIR}/data
    ${SRC_DIR}/blocks
)

set(CATCH_SRC ${SRC_DIR}/libs/catch_amalgamated.cpp)

# Dò các source cần build
file(GLOB_RECURSE CORE_SOURCES
    "${SRC_DIR}/core/*.cpp"
    "${SRC_DIR}/data/*.cpp"
    "${SRC_DIR}/blocks/*.cpp"
)

file(GLOB TEST_SOURCES
    "${SRC_DIR}/build/*.cpp"
)

# Tạo test binary cho từng file test
foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)

    add_executable(${test_name}
        ${test_file}
        ${CATCH_SRC}
        ${CORE_SOURCES}
    )

    # Link raylib vào binary test
    target_link_libraries(${test_name} ${RAYLIB_LIBRARIES})

    set_target_properties(${test_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${SRC_DIR}/test
    )
endforeach()
