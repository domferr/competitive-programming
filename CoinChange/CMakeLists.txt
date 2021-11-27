add_executable(
        coin_change_test
        tests.cpp
        coin_change.cpp
        coin_change.h
)
target_link_libraries(
        coin_change_test
        gtest_main
)

gtest_discover_tests(coin_change_test)