add_executable(
        gold_mine_problem_test
        tests.cpp
        gold_mine_problem.tpp
        gold_mine_problem.h
)
target_link_libraries(
        gold_mine_problem_test
        gtest_main
)

gtest_discover_tests(gold_mine_problem_test)