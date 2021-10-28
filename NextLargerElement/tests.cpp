//
// Created by Domenico on 28/10/2021.
//

#include <gtest/gtest.h>
#include "nextlargerelement.h"

TEST(SlidingWindowMaximumTest1, BasicAssertions) {
    std::vector<int> elements {1, 3, 2, 4};
    std::vector<int> solution = {3, 4, 4, -1};
    auto res = nextlargerelement(elements);
    EXPECT_EQ(res, solution);
}

TEST(SlidingWindowMaximumTest2, BasicAssertions) {
    std::vector<int> elements {6, 8, 0, 1, 3};
    std::vector<int> solution = {8, -1, 1, 3, -1};
    auto res = nextlargerelement(elements);
    EXPECT_EQ(res, solution);
}