add_executable(
        kirkpatrick_seidel_test
        kirkpatrick_seidel.cpp
        kirkpatrick_seidel.h
        ../utils/utils.cpp
        ../utils/utils.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.cpp
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        kirkpatrick_seidel_test
        gtest_main
)

gtest_discover_tests(kirkpatrick_seidel_test)