add_executable(
        fenwick_tree_test
        unit_tests.cpp
        fenwicktree.tpp fenwicktree.h)
target_link_libraries(
        fenwick_tree_test
        gtest_main
)

gtest_discover_tests(fenwick_tree_test)