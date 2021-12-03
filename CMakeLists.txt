cmake_minimum_required(VERSION 3.16)
project(selector)

set(CMAKE_CXX_STANDARD 14)

if(WITH_TESTS OR WITH_SANITIZERS OR WITH_COVERAGE)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()

enable_testing()
find_package(GTest REQUIRED)
set(BUILD_TESTS ON)


add_subdirectory(lib/Selector)

add_executable(Selector main.cpp)
target_link_libraries(Selector FlatSelector)
