//
// Created by Domenico on 09/11/2021.
//

#include <gtest/gtest.h>
#include "fenwicktree.h"

TEST(FenwickTreeTestInitializerList, BasicAssertions) {
    fenwicktree ft { 3, 2, -1, 5, 7, -3, 2, 1 };
    EXPECT_EQ(ft.size(), 8);
}

TEST(FenwickTreeTestConstructVector, BasicAssertions) {
    std::vector<int> vec{ 3, 2, -1, 5, 7, -3, 2, 1 };
    fenwicktree ft { vec };
    EXPECT_EQ(ft.size(), 8);
}

TEST(FenwickTreeTestVal, BasicAssertions) {
    std::vector<int> values {3, 2, -1, 5, 7, -3, 2, 1};
    fenwicktree ft { values };
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft[i], values[i]);
    }
}

TEST(FenwickTreeTestSum, BasicAssertions) {
    fenwicktree ft { 3, 2, -1, 5, 7, -3, 2, 1 };
    std::vector<int> sums {3,5,4,9,16,13,15,16};
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft.sum(i), sums[i]);
    }
}

/* Test rangesum(i,j) with every possible pair (i,j) and i <= j */
TEST(FenwickTreeTestRangeSum, BasicAssertions) {
    fenwicktree ft{ 3, 2, -1, 5, 7, -3, 2, 1 };
    std::vector<int> sums {3,5,4,9,16,13,15,16};
    for (int i = 0; i < ft.size(); ++i) {
        for (int j = i; j < ft.size(); ++j) {
            int left_sum = i == 0 ? 0:sums[i-1];
            EXPECT_EQ(ft.rangesum(i, j), sums[j] - left_sum);
        }
    }
}