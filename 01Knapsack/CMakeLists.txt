add_executable(
        01knapsack_test
        tests.cpp
        01knapsack.cpp 01knapsack.h)
target_link_libraries(
        01knapsack_test
        gtest_main
)

gtest_discover_tests(01knapsack_test)