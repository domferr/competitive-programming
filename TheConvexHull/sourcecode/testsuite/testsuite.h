//
// Created by Domenico on 25/01/2022.
//

#ifndef COMPETITIVE_PROGRAMMING_COMMONTESTS_H
#define COMPETITIVE_PROGRAMMING_COMMONTESTS_H

#include "../utils/point.h"

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

#endif //COMPETITIVE_PROGRAMMING_COMMONTESTS_H
