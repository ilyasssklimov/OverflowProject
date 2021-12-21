add_executable(test_datalib
        src/test_sqlite_database.cpp)

target_link_libraries(test_datalib datalib
                                   GTest::Main)
add_test(NAME test_datalib COMMAND test_datalib)