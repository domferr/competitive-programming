//
// Created by Domenico on 21/11/2021.
//

#include <gtest/gtest.h>
#include "minimum_cost_path.h"

TEST(MinimumCostPathTest1, BasicAssertions) {
    int matrix[3][4] = {
        { 1, 2, 6, 9 },
        { 0, 0, 3, 1 },
        { 1, 7, 7, 2 },
    };

    int solution = 7;
    int res = minimum_cost_path(matrix);
    EXPECT_EQ(res, solution);
}

TEST(MinimumCostPathTest2, BasicAssertions) {
    int matrix[5][4] = {
        { 1, 4, 6, 4 },
        { 2, 6, 0, 1 },
        { 1, 8, 7, 3 },
        { 9, 0, 0, 1 },
        { 4, 5, 7, 2 },
    };

    int solution = 15;
    int res = minimum_cost_path(matrix);
    EXPECT_EQ(res, solution);
}