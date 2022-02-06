add_executable(
        preparata_test
        preparata.cpp
        preparata.h
        ../utils/utils.cpp
        ../utils/utils.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.cpp
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        preparata_test
        gtest_main
)

gtest_discover_tests(preparata_test)