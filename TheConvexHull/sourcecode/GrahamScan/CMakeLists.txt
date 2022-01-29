add_executable(
        graham_scan_test
        grahamscan.cpp
        grahamscan.h
        ../utils/utils.cpp
        ../utils/utils.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.cpp
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        graham_scan_test
        gtest_main
)

gtest_discover_tests(graham_scan_test)