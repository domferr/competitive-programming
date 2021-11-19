add_executable(
        house_robber_test
        tests.cpp
        houserobber.cpp houserobber.h)
target_link_libraries(
        house_robber_test
        gtest_main
)

gtest_discover_tests(house_robber_test)