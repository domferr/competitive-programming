add_executable(
        monotone_chain_test
        monotonechain.cpp
        monotonechain.h
        ../utils/utils.cpp
        ../utils/utils.h
        ../utils/point.cpp
        ../utils/point.h
        ../testsuite/testsuite.cpp
        ../testsuite/testsuite.h
        tests.cpp
)
target_link_libraries(
        monotone_chain_test
        gtest_main
)

gtest_discover_tests(monotone_chain_test)