//
// Created by Domenico on 28/10/2021.
//

#include <gtest/gtest.h>
#include "trappingrainwater.h"

// Demonstrate some basic assertions.
TEST(TrappingRainWaterTest, BasicAssertions) {
    std::vector<int> vector;
    vector.reserve(6);
    vector.push_back(3);
    vector.push_back(0);
    vector.push_back(0);
    vector.push_back(2);
    vector.push_back(0);
    vector.push_back(4);
    int total_trapped_water = trapping_rain_water(vector);
    EXPECT_EQ(total_trapped_water, 10);
}
