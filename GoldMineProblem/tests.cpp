//
// Created by Domenico on 27/11/2021.
//

#include <gtest/gtest.h>
#include "gold_mine_problem.h"

TEST(GoldMineProblemTest1, BasicAssertions) {
    int mat[3][3] = {
        {1, 3, 3},
        {2, 1, 4},
        {0, 6, 4}
    };
    int res = gold_mine(mat);
    int solution = 12;
    EXPECT_EQ(res, solution);
}

TEST(GoldMineProblemTest2, BasicAssertions) {
    int mat[4][4] = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int res = gold_mine(mat);
    int solution = 16;
    EXPECT_EQ(res, solution);
}

TEST(GoldMineProblemTest3, BasicAssertions) {
    int mat[4][4] = {
        {10, 33, 13, 15},
        {22, 21, 04, 1},
        {5, 0, 2, 3},
        {0, 6, 14, 2}
    };
    int res = gold_mine(mat);
    int solution = 83;
    EXPECT_EQ(res, solution);
}