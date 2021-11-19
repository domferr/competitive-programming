add_executable(
        missing_number_test
        tests.cpp
        missingnumber.cpp missingnumber.h)
target_link_libraries(
        missing_number_test
        gtest_main
)

gtest_discover_tests(missing_number_test)