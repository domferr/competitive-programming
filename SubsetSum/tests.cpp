//
// Created by Domenico on 28/11/2021.
//

#include <gtest/gtest.h>
#include "subset_sum.h"

TEST(SubsetSumTest1, BasicAssertions) {
    int sum = 6;
    std::vector<int> arr { 3, 2, 5, 1 };
    bool res = subset_sum(arr, sum);
    bool solution = true;
    EXPECT_EQ(res, solution);
}

TEST(SubsetSumTest2, BasicAssertions) {
    int sum = 9;
    std::vector<int> arr { 3, 34, 4, 12, 5, 2 };
    bool res = subset_sum(arr, sum);
    bool solution = true;
    EXPECT_EQ(res, solution);
}

TEST(SubsetSumTest3, BasicAssertions) {
    int sum = 30;
    std::vector<int> arr { 3, 34, 4, 12, 5, 2 };
    bool res = subset_sum(arr, sum);
    bool solution = false;
    EXPECT_EQ(res, solution);
}
