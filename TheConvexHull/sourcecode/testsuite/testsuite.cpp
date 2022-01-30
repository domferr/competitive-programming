//
// Created by Domenico on 29/01/2022.
//

#include <gtest/gtest.h>
#include <vector>
#include "testsuite.h"
#include "../utils/utils.h"

std::vector<Point> get_test_set_1() {
    return { P(0, 0), P(10, 0), P(0, 10) };
}

std::vector<Point> get_solution_set_1() {
    return {P(0, 0), P(10, 0), P(0, 10)};
}

std::vector<Point> get_test_set_2() {
    return { P(41, -6), P(-24, -74), P(-51, -6), P(73, 17), P(-30, -34) };
}

std::vector<Point> get_solution_set_2() {
    return { P(-24, -74), P(73, 17), P(-51, -6) };
}

std::vector<Point> get_test_set_3() {
    return { P(-75, -13), P(102, 8), P(-50, -72), P(66, -55), P(-23, 44),
             P(37, 24), P(28, -29), P(-29, 28), P(-28, 20), P(56, 69),
             P(-50, 59)};
}

std::vector<Point> get_solution_set_3() {
    return { P(-75, -13), P(-50, -72), P(66, -55), P(102, 8), P(56, 69), P(-50, 59)};
}

void compare_convex_hulls(const std::vector<Point> &ch1, const std::vector<Point> &ch2) {
    EXPECT_EQ(ch1.size(), ch2.size());

    int leftMostIndexCh1 = get_leftmost_point_index(ch1);
    int leftMostIndexCh2 = get_leftmost_point_index(ch2);
    EXPECT_EQ(ch1[leftMostIndexCh1], ch2[leftMostIndexCh2]);

    int remaining = ch1.size();
    while (remaining > 0) {
        EXPECT_EQ(ch1[leftMostIndexCh1], ch2[leftMostIndexCh2]);
        remaining--;
        leftMostIndexCh1 = (leftMostIndexCh1+1) % ch1.size();
        leftMostIndexCh2 = (leftMostIndexCh2+1) % ch2.size();
    }
}