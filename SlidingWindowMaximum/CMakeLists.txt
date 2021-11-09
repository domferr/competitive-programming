add_executable(
        sliding_window_maximum_test
        slidingwindowmaximum.tpp
        slidingwindowmaximum.h
        tests.cpp)
target_link_libraries(
        sliding_window_maximum_test
        gtest_main
)

gtest_discover_tests(sliding_window_maximum_test)