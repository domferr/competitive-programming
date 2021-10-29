cmake_minimum_required(VERSION 3.20)
project(longtermproblem)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        long_term_problem_test
        longtermproblem.cpp
        longtermproblem.h
        tests.cpp)
target_link_libraries(
        long_term_problem_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(long_term_problem_test)