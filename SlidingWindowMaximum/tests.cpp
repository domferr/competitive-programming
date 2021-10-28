//
// Created by Domenico on 28/10/2021.
//

#include <gtest/gtest.h>
#include "slidingwindowmaximum.h"

TEST(SlidingWindowMaximumTest1, BasicAssertions) {
    std::vector<int> vector {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    std::vector<int> solution = {3, 3, 4, 5, 5, 5, 6};
    auto res = slidingwindowmax(vector, k);
    EXPECT_EQ(res, solution);
}

TEST(SlidingWindowMaximumTest2, BasicAssertions) {
    std::vector<int> vector {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 4;
    std::vector<int> solution = {10, 10, 10, 15, 15, 90, 90};
    auto res = slidingwindowmax(vector, k);
    EXPECT_EQ(res, solution);
}
