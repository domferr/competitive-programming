//
// Created by Domenico on 25/01/2022.
//

#ifndef COMPETITIVE_PROGRAMMING_COMMONTESTS_H
#define COMPETITIVE_PROGRAMMING_COMMONTESTS_H

#include "../utils/point.h"

std::vector<Point> get_test_set_1();
std::vector<Point> get_solution_set_1();

std::vector<Point> get_test_set_2();
std::vector<Point> get_solution_set_2();

std::vector<Point> get_test_set_3();
std::vector<Point> get_solution_set_3();

void compare_convex_hulls(const std::vector<Point> &ch1, const std::vector<Point> &ch2);

#define EXPECT_CH_EQ(ch1, ch2) compare_convex_hulls(ch1, ch2)

#endif //COMPETITIVE_PROGRAMMING_COMMONTESTS_H
