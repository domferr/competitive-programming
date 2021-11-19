add_executable(
        kadanes_algorithm_test
        tests.cpp
        kadanesalgorithm.cpp
        kadanesalgorithm.h)
target_link_libraries(
        kadanes_algorithm_test
        gtest_main
)

gtest_discover_tests(kadanes_algorithm_test)