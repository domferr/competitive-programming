add_executable(
        max_segment_intersections_test
        maxsegmentintersections.cpp
        maxsegmentintersections.h
        tests.cpp
)
target_link_libraries(
        max_segment_intersections_test
        gtest_main
)

gtest_discover_tests(max_segment_intersections_test)