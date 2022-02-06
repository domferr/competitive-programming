//
// Created by Domenico on 25/01/2022.
//

#include <gtest/gtest.h>
#include "chan.h"
#include "../testsuite/testsuite.h"

TEST(ChanTest3, BasicAssertions) {
    std::vector<Point> points = get_test_set_3();
    std::vector<Point> res = chan(points);
    EXPECT_CH_EQ(res, get_solution_set_3());
}

TEST(ChanTest2, BasicAssertions) {
    std::vector<Point> points = get_test_set_2();
    std::vector<Point> res = chan(points);
    EXPECT_CH_EQ(res, get_solution_set_2());
}

TEST(ChanTest1, BasicAssertions) {
    std::vector<Point> points = get_test_set_1();
    std::vector<Point> res = chan(points);
    EXPECT_CH_EQ(res, get_solution_set_1());
}