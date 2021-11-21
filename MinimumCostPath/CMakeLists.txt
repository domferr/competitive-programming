add_executable(
        minimum_cost_path_test
        tests.cpp
        minimum_cost_path.tpp
        minimum_cost_path.h
)
target_link_libraries(
        minimum_cost_path_test
        gtest_main
)

gtest_discover_tests(minimum_cost_path_test)