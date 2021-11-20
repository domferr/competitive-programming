add_executable(
        towers_test
        tests.cpp
        towers.cpp
        towers.h)
target_link_libraries(
        towers_test
        gtest_main
)

gtest_discover_tests(towers_test)