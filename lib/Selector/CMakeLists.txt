add_library(ParseJson src/ParseJson.cpp)
add_library(GetTravelTime src/GetTravelTime.cpp)
add_library(FlatSelector src/FlatSelector.cpp)

find_package(CURL REQUIRED)
find_package(RapidJSON REQUIRED)
include_directories(${RAPIDJSON_INCLUDE_DIR})

target_include_directories(ParseJson PUBLIC include)
target_include_directories(GetTravelTime PUBLIC include)
target_include_directories(FlatSelector PUBLIC include)

target_link_libraries(GetTravelTime CURL::libcurl ParseJson)
target_link_libraries(FlatSelector GetTravelTime )

