add_library(ArgumentsParser src/ArgumentsParser.cpp)

target_include_directories(ArgumentsParser PUBLIC include)
target_link_libraries(ArgumentsParser CURL::libcurl rapidjson JsonReader UrlsReader datalib)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()