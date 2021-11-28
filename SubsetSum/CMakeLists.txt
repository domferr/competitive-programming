add_executable(
        subset_sum_test
        tests.cpp
        subset_sum.cpp
        subset_sum.h
)
target_link_libraries(
        subset_sum_test
        gtest_main
)

gtest_discover_tests(subset_sum_test)