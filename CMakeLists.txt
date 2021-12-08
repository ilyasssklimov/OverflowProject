cmake_minimum_required(VERSION 3.21)
project(overflow)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Wpedantic)

option(WITH_TESTS "Build tests")
if (WITH_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()

add_subdirectory(lib/datalib)

add_executable(main src/main.cpp)

target_link_libraries(main datalib)