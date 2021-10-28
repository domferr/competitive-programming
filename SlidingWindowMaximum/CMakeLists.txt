cmake_minimum_required(VERSION 3.20)
project(slidingwindowmaximum)

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
        sliding_window_maximum_test
        slidingwindowmaximum.tpp
        slidingwindowmaximum.h
        tests.cpp)
target_link_libraries(
        sliding_window_maximum_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(sliding_window_maximum_test)