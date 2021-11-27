//
// Created by Domenico on 27/11/2021.
//

#include <gtest/gtest.h>
#include "01knapsack.h"

TEST(ZeroOneKnapsackTest1, BasicAssertions) {
    int max_capacity = 4;
    std::vector<item> items { ITEM(1, 8), ITEM(2, 4), ITEM(3, 0), ITEM(2, 5), ITEM(2, 3) };
    int res = zero_one_knapsack(items, max_capacity);
    int solution = 13;
    EXPECT_EQ(res, solution);
}

TEST(ZeroOneKnapsackTest2, BasicAssertions) {
    int max_capacity = 7;
    std::vector<item> items { ITEM(1, 1), ITEM(3, 4), ITEM(4, 5), ITEM(5, 7) };
    int res = zero_one_knapsack(items, max_capacity);
    int solution = 9;
    EXPECT_EQ(res, solution);
}