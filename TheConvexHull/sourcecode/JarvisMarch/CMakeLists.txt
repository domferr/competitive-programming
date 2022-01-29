add_executable(
        jarvis_march_test
        jarvismarch.cpp
        jarvismarch.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        jarvis_march_test
        gtest_main
)

gtest_discover_tests(jarvis_march_test)