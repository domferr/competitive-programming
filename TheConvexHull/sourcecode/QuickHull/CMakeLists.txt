add_executable(
        quick_hull_test
        quickhull.cpp
        quickhull.h
        ../utils/utils.cpp
        ../utils/utils.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.cpp
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        quick_hull_test
        gtest_main
)

gtest_discover_tests(quick_hull_test)