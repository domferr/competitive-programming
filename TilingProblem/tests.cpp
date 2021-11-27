//
// Created by Domenico on 27/11/2021.
//

#include <gtest/gtest.h>
#include "tiling_problem.h"

TEST(TilingProblemTest1, BasicAssertions) {
    int n = 4;
    int res = tiling_problem(n);
    int solution = 3;
    EXPECT_EQ(res, solution);
}

TEST(TilingProblemTest2, BasicAssertions) {
    int n = 3;
    int res = tiling_problem(n);
    int solution = 2;
    EXPECT_EQ(res, solution);
}