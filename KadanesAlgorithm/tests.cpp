//
// Created by Domenico on 19/11/2021.
//

#include <gtest/gtest.h>
#include "kadanesalgorithm.h"

TEST(KadanesAlgorithmTest1, BasicAssertions) {
    std::vector<int> numbers {1,2,3,-2,5};
    size_t res = kadanesalgorithm(numbers);
    size_t solution = 9;
    EXPECT_EQ(res, solution);
}

TEST(KadanesAlgorithmTest2, BasicAssertions) {
    std::vector<int> numbers {-1,-2,-3,-4};
    size_t res = kadanesalgorithm(numbers);
    size_t solution = -1;
    EXPECT_EQ(res, solution);
}

TEST(KadanesAlgorithmTest3, BasicAssertions) {
    std::vector<int> numbers {-1,9,-2,4};
    size_t res = kadanesalgorithm(numbers);
    size_t solution = 11;
    EXPECT_EQ(res, solution);
}

TEST(KadanesAlgorithmTest4, BasicAssertions) {
    std::vector<int> numbers {1,-7,8};
    size_t res = kadanesalgorithm(numbers);
    size_t solution = 8;
    EXPECT_EQ(res, solution);
}