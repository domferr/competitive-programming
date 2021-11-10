//
// Created by Domenico on 09/11/2021.
//

#include <gtest/gtest.h>
#include "nestedsegments.h"

#define SEG(start, end) (std::make_pair((start), (end)))

void test(std::vector<std::pair<int, int>> &segments, std::vector<int> &solution) {
    std::vector<int> res = nested_segments(segments);
    EXPECT_EQ(res.size(), solution.size());
    for (int i = 0; i < solution.size(); ++i) {
        EXPECT_EQ(res[i], solution[i]);
    }
}

TEST(NestedSegmentsTest1, BasicAssertions) {
    std::vector<std::pair<int, int>> segments { SEG(1,8), SEG(2,3), SEG(4,7), SEG(5,6) };
    std::vector<int> solution { 3, 0, 1, 0 };

    test(segments, solution);
}

TEST(NestedSegmentsTest2, BasicAssertions) {
    std::vector<std::pair<int, int>> segments { SEG(3,4), SEG(1,5), SEG(2,6) };
    std::vector<int> solution { 0, 1, 1 };

    test(segments, solution);
}

TEST(NestedSegmentsTest3, BasicAssertions) {
    // test case with two segments that have the same starting position
    std::vector<std::pair<int, int>> segments { SEG(3,4), SEG(3,5), SEG(2,6) };
    std::vector<int> solution { 0, 1, 2 };

    test(segments, solution);
}