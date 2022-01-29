//
// Created by Domenico on 29/01/2022.
//

#include "point.h"

Point::Point(int x, int y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "[" << point.x << ", " << point.y << "]";
    return os;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}
