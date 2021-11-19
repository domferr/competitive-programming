add_executable(
        rod_cutting_test
        tests.cpp
        rodcutting.cpp rodcutting.h)
target_link_libraries(
        rod_cutting_test
        gtest_main
)

gtest_discover_tests(rod_cutting_test)