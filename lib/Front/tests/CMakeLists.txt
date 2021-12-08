add_executable(test_frontend src/test.cpp)
target_link_libraries(test_frontend wt wthttp)
target_include_directories(test_frontend PUBLIC ../include)
add_test(NAME test_frontend COMMAND test_frontend)