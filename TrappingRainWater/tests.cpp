//
// Created by Domenico on 28/10/2021.
//

#include <gtest/gtest.h>
#include "trappingrainwater.h"

TEST(TrappingRainWaterTest1, BasicAssertions) {
    std::vector<int> vector { 3, 0, 0, 2, 0, 4};
    int total_trapped_water = trapping_rain_water(vector);
    EXPECT_EQ(total_trapped_water, 10);
}

TEST(TrappingRainWaterTest2, BasicAssertions) {
    std::vector<int> vector { 7, 4, 0, 9};
    int total_trapped_water = trapping_rain_water(vector);
    EXPECT_EQ(total_trapped_water, 10);
}

TEST(TrappingRainWaterTest3, BasicAssertions) {
    std::vector<int> vector { 6, 9, 9 };
    int total_trapped_water = trapping_rain_water(vector);
    EXPECT_EQ(total_trapped_water, 0);
}
