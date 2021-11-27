//
// Created by Domenico on 27/11/2021.
//

#include <gtest/gtest.h>
#include "coin_change.h"

TEST(CoinChangeTest1, BasicAssertions) {
    int n = 4;
    std::vector<int> coins { 1, 2, 3 };
    int res = coin_change(n, coins);
    int solution = 4;
    EXPECT_EQ(res, solution);
}

TEST(CoinChangeTest2, BasicAssertions) {
    int n = 10;
    std::vector<int> coins { 2, 5, 3, 6 };
    int res = coin_change(n, coins);
    int solution = 5;
    EXPECT_EQ(res, solution);
}