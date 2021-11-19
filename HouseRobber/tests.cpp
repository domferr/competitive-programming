//
// Created by Domenico on 19/11/2021.
//

#include <gtest/gtest.h>
#include "houserobber.h"

TEST(HouseRobberTest1, BasicAssertions) {
    std::vector<int> revenues {1,2,3,1};
    int res = houserobber(revenues);
    int solution = 4;
    EXPECT_EQ(res, solution);
}

TEST(HouseRobberTest2, BasicAssertions) {
    std::vector<int> revenues {2,7,9,3,1};
    int res = houserobber(revenues);
    int solution = 12;
    EXPECT_EQ(res, solution);
}