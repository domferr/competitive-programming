//
// Created by Domenico on 25/01/2022.
//

#include <gtest/gtest.h>
#include "grahamscan.h"
#include "../testsuite/testsuite.h"
#include "../utils/utils.h"

TEST(GrahamScanTest1, BasicAssertions) {
    std::vector<Point> points = get_test_set_1();
    std::vector<Point> res = grahamscan(points);
    EXPECT_CH_EQ(res, get_solution_set_1());
}

TEST(GrahamScanTest2, BasicAssertions) {
    std::vector<Point> points = get_test_set_2();
    std::vector<Point> res = grahamscan(points);
    EXPECT_CH_EQ(res, get_solution_set_2());
}