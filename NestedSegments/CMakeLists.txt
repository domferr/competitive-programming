add_executable(
        nested_segments_test
        tests.cpp
        ../FenwickTree/fenwicktree.h
        ../FenwickTree/fenwicktree.tpp
        nestedsegments.cpp nestedsegments.h)
target_link_libraries(
        nested_segments_test
        gtest_main
)

gtest_discover_tests(nested_segments_test)