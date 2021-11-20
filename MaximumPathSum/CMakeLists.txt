add_executable(
        maximum_path_sum_test
        tests.cpp
        maximum_path_sum.cpp
        maximum_path_sum.h
)
target_link_libraries(
        maximum_path_sum_test
        gtest_main
)

gtest_discover_tests(maximum_path_sum_test)