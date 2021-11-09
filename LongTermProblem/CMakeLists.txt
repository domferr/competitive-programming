add_executable(
        long_term_problem_test
        longtermproblem.cpp
        longtermproblem.h
        tests.cpp)
target_link_libraries(
        long_term_problem_test
        gtest_main
)

gtest_discover_tests(long_term_problem_test)