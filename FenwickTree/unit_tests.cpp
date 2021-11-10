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

TEST(FenwickTreeTestStartingValueConstructor, BasicAssertions) {
    fenwicktree<int> ft ( 4, 17 );
    EXPECT_EQ(ft.size(), 4);
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft[i], 17);
    }
}

TEST(FenwickTreeTestSum, BasicAssertions) {
    fenwicktree<int> ft { 3, 2, -1, 5, 7, -3, 2, 1 };
    std::vector<int> sums {3,5,4,9,16,13,15,16};
    for (int i = 0; i < ft.size(); ++i) {
        EXPECT_EQ(ft.sum(i), sums[i]);
    }
}

TEST(FenwickTreeTestAdd, BasicAssertions) {
    std::vector<int> original_values { 3, 2, -1, 5, 7, -3, 2, 1 };
    fenwicktree<int> ft { original_values };
    int val = 4;
    size_t pos = 3;
    ft.add(pos, val);
    std::vector<int> old_sums { 3,5,4,9,16,13,15,16 };
    EXPECT_EQ(ft[pos], original_values[pos] + val);
    for (size_t i = pos; i < ft.size(); ++i) {
        EXPECT_EQ(ft.sum(i), old_sums[i] + val);
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

template<class C>
void test_update(std::vector<C> &original_values, size_t pos, C new_value ) {
    fenwicktree<C> ft { original_values };
    // update the value
    ft.update(pos, new_value);

    // check if the original value is now the new one
    EXPECT_EQ(ft[pos], new_value);

    // compute the sums taking into account this new value
    std::vector<C> new_sums(original_values.size());
    C diff = new_value - original_values[pos];
    for (int i = 0; i < new_sums.size(); ++i) {
        new_sums[i] = original_values[i];
        if (i > 0) new_sums[i] += new_sums[i-1];
        if (i == pos) new_sums[i] += diff;
    }

    // compare ft.sum(i) with the correct sum
    for (size_t i = pos; i < ft.size(); ++i) {
        EXPECT_EQ(ft.sum(i), new_sums[i]);
    }
}

TEST(FenwickTreeTestUpdate, BasicAssertions) {
    std::vector<int> original_values { 3, 2, -1, 5, 7, -3, 2, 1 };
    size_t pos = 3; // number 5
    // Test with a value less than the old value
    test_update(original_values, pos, 1);
    // Test with a value equal to the old value
    test_update(original_values, pos, 5);
    // Test with a value greater than the old value
    test_update(original_values, pos, 10);
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
    CustomInt operator+(const CustomInt& other) const { return {val + other.val}; }
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
    // test update() operation with custom class
    test_update(original_values, 3, CustomInt(19));
}