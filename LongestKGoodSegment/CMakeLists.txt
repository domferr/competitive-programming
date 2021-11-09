add_executable(
        longest_k_good_segment_test
        longestkgoodsegment.cpp
        longestkgoodsegment.h
        tests.cpp
)
target_link_libraries(
        longest_k_good_segment_test
        gtest_main
)

gtest_discover_tests(longest_k_good_segment_test)