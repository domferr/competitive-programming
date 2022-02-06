//
// Created by Domenico on 25/01/2022.
//

#include <gtest/gtest.h>
#include "preparata.h"
#include "../testsuite/testsuite.h"

TEST(PreparataTest1, BasicAssertions) {
    std::vector<Point> points = get_test_set_1();
    // Sort points by x-coordinate or by y-coordinate if there is a tie
    std::sort(points.begin(), points.end(), [](Point &p1, Point &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    });
    std::vector<Point> res = preparata(points, 0, points.size());
    EXPECT_CH_EQ(res, get_solution_set_1());
}

TEST(PreparataTest2, BasicAssertions) {
    std::vector<Point> points = get_test_set_2();
    // Sort points by x-coordinate or by y-coordinate if there is a tie
    std::sort(points.begin(), points.end(), [](Point &p1, Point &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    });
    std::vector<Point> res = preparata(points, 0, points.size());
    EXPECT_CH_EQ(res, get_solution_set_2());
}

TEST(PreparataTest3, BasicAssertions) {
    std::vector<Point> points = get_test_set_3();
    // Sort points by x-coordinate or by y-coordinate if there is a tie
    std::sort(points.begin(), points.end(), [](Point &p1, Point &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    });
    std::vector<Point> res = preparata(points, 0, points.size());
    EXPECT_CH_EQ(res, get_solution_set_3());
}