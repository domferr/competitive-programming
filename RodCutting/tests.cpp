//
// Created by Domenico on 19/11/2021.
//

#include <gtest/gtest.h>
#include "rodcutting.h"

TEST(RodCuttingTest1, BasicAssertions) {
    std::vector<int> prices {1, 5, 8, 9, 10, 17, 17, 20};
    int res = rodcutting(prices);
    int solution = 22;
    EXPECT_EQ(res, solution);
}

TEST(RodCuttingTest2, BasicAssertions) {
    std::vector<int> prices { 3, 5, 8, 9, 10, 17, 17, 20 };
    int res = rodcutting(prices);
    int solution = 24;
    EXPECT_EQ(res, solution);
}