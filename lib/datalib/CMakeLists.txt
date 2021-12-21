add_library(datalib src/sqlite_database.cpp
                    src/db_exception.cpp
        src/flat.cpp)

target_include_directories(datalib PUBLIC include)

if (WIN32)
    target_include_directories(datalib PUBLIC C:/sqlite)
    target_link_directories(datalib PUBLIC C:/sqlite)
elseif(UNIX)
    find_package(SQLite3 REQUIRED)
endif()

target_link_libraries(datalib sqlite3)


if(BUILD_TESTS)
    add_subdirectory(tests)
endif()