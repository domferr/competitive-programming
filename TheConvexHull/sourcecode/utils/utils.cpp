//
// Created by Domenico on 29/01/2022.
//

#include "utils.h"

int orientation(const Point &a, const Point &b, const Point &c) {
    int val = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);
    if (val == 0) return COL;
    return (val > 0) ? CW: CCW;
}

int dist_sq(const Point &p1, const Point &p2) {
    return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
}

int leftmost_point_index(const std::vector<Point> &points) {
    int index = 0;
    Point leftmost = points[index];
    for (int i = 0; i<points.size(); ++i) {
        Point p = points[i];
        if (p.x < leftmost.x || (p.x == leftmost.x && p.y < leftmost.y)) {
            leftmost = p;
            index = i;
        }
    }
    return index;
}

int rightmost_point_index(const std::vector<Point> &points) {
    int index = 0;
    Point rightmost = points[index];
    for (int i = 0; i<points.size(); ++i) {
        Point p = points[i];
        if (p.x > rightmost.x || (p.x == rightmost.x && p.y < rightmost.y)) {
            rightmost = p;
            index = i;
        }
    }
    return index;
}