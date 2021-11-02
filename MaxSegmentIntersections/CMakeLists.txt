cmake_minimum_required(VERSION 3.20)
project(maxsegmentintersections)

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
        max_segment_intersections_test
        tests.cpp maxsegmentintersections.cpp maxsegmentintersections.h)
target_link_libraries(
        max_segment_intersections_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(max_segment_intersections_test)