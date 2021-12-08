add_library(datalib src/sqlite_database.cpp
                    src/db_exception.cpp
                    src/flat_params.cpp
                    src/flat.cpp)

target_include_directories(datalib PUBLIC include)
target_include_directories(datalib PUBLIC db)

target_include_directories(datalib PUBLIC C:/sqlite)
target_link_directories(datalib PUBLIC C:/sqlite)
target_link_libraries(datalib sqlite3)


if(BUILD_TESTS)
    add_subdirectory(tests)
endif()