add_executable(
        bst_test
        bst.h
        bst.tpp
        bst_inorder_iterator.h
        unit_tests.cpp
        bst_utils.h
)
target_link_libraries(
        bst_test
        gtest_main
)

gtest_discover_tests(bst_test)