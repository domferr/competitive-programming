//
// Created by Domenico on 25/01/2022.
//

#include <gtest/gtest.h>
#include "monotonechain.h"
#include "../testsuite/testsuite.h"

TEST(MonotoneChainTest1, BasicAssertions) {
    std::vector<Point> points = get_test_set_1();
    std::vector<Point> res = monotonechain(points);
    EXPECT_CH_EQ(res, get_solution_set_1());
}

TEST(MonotoneChainTest2, BasicAssertions) {
    std::vector<Point> points = get_test_set_2();
    std::vector<Point> res = monotonechain(points);
    EXPECT_CH_EQ(res, get_solution_set_2());
}

TEST(MonotoneChainTest3, BasicAssertions) {
    std::vector<Point> points = get_test_set_3();
    std::vector<Point> res = monotonechain(points);
    EXPECT_CH_EQ(res, get_solution_set_3());
}