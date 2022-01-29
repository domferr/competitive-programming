//
// Created by Domenico on 25/01/2022.
//

#ifndef COMPETITIVE_PROGRAMMING_POINT_H
#define COMPETITIVE_PROGRAMMING_POINT_H

#include <ostream>

#define P(x, y) Point(x, y)

struct Point {
    int x;
    int y;

    Point(int x, int y);

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

};

#endif //COMPETITIVE_PROGRAMMING_POINT_H
