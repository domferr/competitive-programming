//
// Created by Domenico on 29/01/2022.
//

#ifndef COMPETITIVE_PROGRAMMING_UTILS_H
#define COMPETITIVE_PROGRAMMING_UTILS_H

#include <vector>
#include "point.h"

#define COL 0
#define CW  1
#define CCW 2

int get_leftmost_point_index(const std::vector<Point> &points);
Point get_leftmost_point(const std::vector<Point> &points);
int get_rightmost_point_index(const std::vector<Point> &points);
Point get_rightmost_point(const std::vector<Point> &points);
int orientation(const Point &a, const Point &b, const Point &c);

// Compute square of distance between p1 and p2
int dist_sq(const Point &p1, const Point &p2);

#endif //COMPETITIVE_PROGRAMMING_UTILS_H
