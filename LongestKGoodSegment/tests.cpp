//
// Created by Domenico on 05/11/2021.
//

#include <gtest/gtest.h>
#include "longestkgoodsegment.h"

TEST(LongestKGoodSegmentTest1, BasicAssertions) {
    size_t start_ptr = 0;
    size_t end_ptr = 0;
    std::vector<int> vec { 1, 1, 2, 3, 3, 3, 4, 4, 4, 1, 3, 2, 3 };
    int k = 3;
    longestkgoodsegment(vec, k, &start_ptr, &end_ptr);
    EXPECT_EQ(start_ptr, 3);
    EXPECT_EQ(end_ptr, 10);
}

TEST(LongestKGoodSegmentTest2, BasicAssertions) {
    size_t start_ptr = 0;
    size_t end_ptr = 0;
    std::vector<int> vec { 1, 1, 3, 2, 3, 2, 3, 3, 1, 1 };
    int k = 3;
    longestkgoodsegment(vec, k, &start_ptr, &end_ptr);
    EXPECT_EQ(start_ptr, 0);
    EXPECT_EQ(end_ptr, 9);
}

TEST(LongestKGoodSegmentTest3, BasicAssertions) {
    size_t start_ptr = 0;
    size_t end_ptr = 0;
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    int k = 5;
    longestkgoodsegment(vec, k, &start_ptr, &end_ptr);
    EXPECT_EQ(start_ptr, 0);
    EXPECT_EQ(end_ptr, 4);
}

TEST(LongestKGoodSegmentTest4, BasicAssertions) {
    size_t start_ptr = 0;
    size_t end_ptr = 0;
    std::vector<int> vec { 6, 5, 1, 2, 3, 2, 1, 4, 5 };
    int k = 3;
    longestkgoodsegment(vec, k, &start_ptr, &end_ptr);
    EXPECT_EQ(start_ptr, 2);
    EXPECT_EQ(end_ptr, 6);
}

TEST(LongestKGoodSegmentTest5, BasicAssertions) {
    size_t start_ptr = 0;
    size_t end_ptr = 0;
    std::vector<int> vec { 1, 2, 3 };
    int k = 1;
    longestkgoodsegment(vec, k, &start_ptr, &end_ptr);
    EXPECT_EQ(start_ptr, 0);
    EXPECT_EQ(end_ptr, 0);
}