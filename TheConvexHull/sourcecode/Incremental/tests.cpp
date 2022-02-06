//
// Created by Domenico on 25/01/2022.
//

#include <gtest/gtest.h>
#include "incremental.h"
#include "../testsuite/testsuite.h"
#include "../utils/utils.h"

TEST(IncrementalTest1, BasicAssertions) {
    std::vector<Point> points = get_test_set_1();
    std::vector<Point> res = incremental(points);
    EXPECT_CH_EQ(res, get_solution_set_1());
}

TEST(IncrementalTest2, BasicAssertions) {
    std::vector<Point> points = get_test_set_2();
    std::vector<Point> res = incremental(points);
    EXPECT_CH_EQ(res, get_solution_set_2());
}

TEST(IncrementalTest3, BasicAssertions) {
    std::vector<Point> points = get_test_set_3();
    std::vector<Point> res = incremental(points);
    EXPECT_CH_EQ(res, get_solution_set_3());
}