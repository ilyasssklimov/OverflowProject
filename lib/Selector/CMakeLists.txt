cmake_minimum_required(VERSION 3.16)
project(FlatSelector)

add_library(FlatSelector src/FlatSelector.cpp src/JsonParser.cpp src/TravelTimeGetter.cpp)

find_package(CURL REQUIRED)
find_package(RapidJSON REQUIRED)
target_include_directories(FlatSelector PRIVATE ${RAPIDJSON_INCLUDE_DIR})
target_include_directories(FlatSelector PUBLIC include)
target_link_libraries(FlatSelector CURL::libcurl datalib)
