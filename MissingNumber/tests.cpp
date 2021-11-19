//
// Created by Domenico on 19/11/2021.
//

#include <gtest/gtest.h>
#include "missingnumber.h"

TEST(MissingNumberTest1, BasicAssertions) {
    std::vector<int> numbers {1,2,3,5};
    size_t res = missingnumber(numbers);
    size_t solution = 4;
    EXPECT_EQ(res, solution);
}

TEST(MissingNumberTest2, BasicAssertions) {
    std::vector<int> numbers {6,1,2,8,3,4,7,10,5};
    size_t res = missingnumber(numbers);
    size_t solution = 9;
    EXPECT_EQ(res, solution);
}