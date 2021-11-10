//
// Created by Domenico on 10/11/2021.
//

#include <gtest/gtest.h>
#include "countinginversions.h"

TEST(CountingInversionsTest1, BasicAssertions) {
    std::vector<int> vec {8, 4, 2, 1};
    int res = counting_inversions_ft(vec);
    EXPECT_EQ(res,6);
}

TEST(CountingInversionsTest2, BasicAssertions) {
    std::vector<int> vec {3, 1, 2};
    int res = counting_inversions_ft(vec);
    EXPECT_EQ(res,2);
}