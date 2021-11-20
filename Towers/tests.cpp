//
// Created by Domenico on 20/11/2021.
//

#include <gtest/gtest.h>
#include "towers.h"

TEST(TowersTest1, BasicAssertions) {
    std::vector<int> bars_len { 1, 2, 3 };
    int largestHeight;
    int totalTowers;
    towers(bars_len, largestHeight, totalTowers);
    EXPECT_EQ(largestHeight, 1);
    EXPECT_EQ(totalTowers, 3);
}

TEST(TowersTest2, BasicAssertions) {
    std::vector<int> bars_len { 6, 5, 6, 7 };
    int largestHeight;
    int totalTowers;
    towers(bars_len, largestHeight, totalTowers);
    EXPECT_EQ(largestHeight, 2);
    EXPECT_EQ(totalTowers, 3);
}

TEST(TowersTest3, BasicAssertions) {
    std::vector<int> bars_len { 6, 5, 6, 9, 5, 1, 5, 6, 3, 5, 4 };
    int largestHeight;
    int totalTowers;
    towers(bars_len, largestHeight, totalTowers);
    EXPECT_EQ(largestHeight, 4);
    EXPECT_EQ(totalTowers, 6);
}