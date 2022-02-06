add_executable(
        incremental_test
        incremental.cpp
        incremental.h
        ../utils/utils.cpp
        ../utils/utils.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.cpp
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        incremental_test
        gtest_main
)

gtest_discover_tests(incremental_test)