add_executable(
        segment_tree_test
        unit_tests.cpp
        segment_tree.tpp segment_tree.h)
target_link_libraries(
        segment_tree_test
        gtest_main
)

gtest_discover_tests(segment_tree_test)