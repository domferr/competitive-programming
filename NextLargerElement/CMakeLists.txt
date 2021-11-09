add_executable(
        next_larger_element_test
        tests.cpp
        nextlargerelement.cpp
        nextlargerelement.h)
target_link_libraries(
        next_larger_element_test
        gtest_main
)

gtest_discover_tests(next_larger_element_test)