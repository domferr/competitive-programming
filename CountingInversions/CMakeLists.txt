add_executable(
        counting_inversions_test
        tests.cpp
        ../FenwickTree/fenwicktree.h
        ../FenwickTree/fenwicktree.tpp
        countinginversions.cpp countinginversions.h)
target_link_libraries(
        counting_inversions_test
        gtest_main
)

gtest_discover_tests(counting_inversions_test)