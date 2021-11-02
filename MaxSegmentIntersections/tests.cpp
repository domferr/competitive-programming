//
// Created by Domenico on 02/11/2021.
//

#include <gtest/gtest.h>
#include "maxsegmentintersections.h"

TEST(MaxSegmentIntersectionTest1, BasicAssertions) {
    std::vector<segment> segments {{1,6}, {5,5}, {2,3}};
    int point_max_int = max_segment_intersections(segments);
    EXPECT_EQ(point_max_int, 2);
}

TEST(MaxSegmentIntersectionTest2, BasicAssertions) {
    std::vector<segment> segments {{4,8}, {1,6},{7,15},{18,23},
                                   {11,21},{10,13}, {17,21}};
    int point_max_int = max_segment_intersections(segments);
    EXPECT_EQ(point_max_int, 11);
}