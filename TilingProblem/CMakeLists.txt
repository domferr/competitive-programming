add_executable(
        tiling_problem_test
        tests.cpp
        tiling_problem.cpp
        tiling_problem.h
)
target_link_libraries(
        tiling_problem_test
        gtest_main
)

gtest_discover_tests(tiling_problem_test)