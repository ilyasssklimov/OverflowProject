cmake_minimum_required(VERSION 3.13)

project(overflow)

add_compile_options(-Wall -Wextra -Wpedantic)

option(WITH_TESTS "Build tests")
if (WITH_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()
