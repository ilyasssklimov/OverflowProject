cmake_minimum_required(VERSION 3.20)
project(OverflowProject)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX STANDARD 14)

message("Добавляю Selector")
add_subdirectory(lib/Selector)

add_subdirectory(lib/Front)
add_executable(main src/main.cpp)
target_link_libraries(main Front)

target_include_directories(main PUBLIC ${HEADERS_DIR})