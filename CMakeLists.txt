project("OverflowProject")
cmake_minimum_required(VERSION 3.21)

add_compile_options(-g)

add_subdirectory(lib/datalib)
add_subdirectory(lib/Parser)
add_subdirectory(lib/Selector)
add_subdirectory(lib/Front)

add_executable(main src/main.cpp)
target_link_libraries(main Front)