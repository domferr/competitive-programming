//
// Created by Domenico on 09/11/2021.
//

#include <gtest/gtest.h>
#include <ostream>
#include "fenwicktree.h"

TEST(FenwickTreeTestInitializerList, BasicAssertions) {
    fenwicktree<int> ft { 3, 2, -1, 5, 7, -3, 2, 1 };
    EXPECT_EQ(ft.size(), 8);
}

TEST(FenwickTreeTestConstructVector, BasicAssertions) {
    std::vector<int> vec{ 3, 2, -1, 5, 7, -3, 2, 1 };
    fenwicktree<int> ft { vec };
    EXPECT_EQ(ft.size(), 8);
}

TEST(FenwickTreeTestOriginalValue, BasicAssertions) {
    std::vector<int> values {3, 2, -1, 5, 7, -3, 2, 1};
    fenwicktree<int> ft { values };
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft[i], values[i]);
    }
}

TEST(FenwickTreeTestSum, BasicAssertions) {
    fenwicktree<int> ft { 3, 2, -1, 5, 7, -3, 2, 1 };
    std::vector<int> sums {3,5,4,9,16,13,15,16};
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft.sum(i), sums[i]);
    }
}

/* Test rangesum(i,j) with every possible pair (i,j) and i <= j */
TEST(FenwickTreeTestRangeSum, BasicAssertions) {
    fenwicktree<int> ft{ 3, 2, -1, 5, 7, -3, 2, 1 };
    std::vector<int> sums {3,5,4,9,16,13,15,16};
    for (int i = 0; i < ft.size(); ++i) {
        for (int j = i; j < ft.size(); ++j) {
            int left_sum = i == 0 ? 0:sums[i-1];
            EXPECT_EQ(ft.rangesum(i, j), sums[j] - left_sum);
        }
    }
}

TEST(FenwickTreeTestFloatNumber, BasicAssertions) {
    std::vector<float> original_values { 3.2, 2.4, -1.2, 5.4, 7.0, -3.6, 2.1, 1.9 };
    fenwicktree<float> ft { original_values };
    EXPECT_EQ(ft.size(), 8);
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_NEAR(ft[i], original_values[i], 0.0001);
    }
    std::vector<float> sums { 3.2, 5.6, 4.4, 9.8, 16.8, 13.2, 15.3, 17.2 };
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_FLOAT_EQ(ft.sum(i), sums[i]);
    }
}

class CustomInt {
private:
    int val;

public:
    CustomInt() = default;
    CustomInt(int val) : val(val) {}

    CustomInt operator-(const CustomInt &rhs) const { return {val - rhs.val}; }
    CustomInt& operator+=(const CustomInt& other) { val += other.val; return *this; }
    bool operator==(const CustomInt &rhs) const { return val == rhs.val; }
    friend std::ostream &operator<<(std::ostream &os, const CustomInt &anInt) { os << anInt.val; return os; }
};

TEST(FenwickTreeTestCustomClass, BasicAssertions) {
    std::vector<CustomInt> original_values { 3, 2, -1, 5, 7, -3, 2, 1 };
    fenwicktree<CustomInt> ft { original_values };
    EXPECT_EQ(ft.size(), 8);
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft[i], original_values[i]);
    }
    std::vector<CustomInt> sums { 3, 5, 4, 9, 16, 13, 15, 16 };
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft.sum(i), sums[i]);
    }
}
