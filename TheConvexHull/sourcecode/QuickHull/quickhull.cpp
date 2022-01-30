//
// Created by Domenico on 26/01/2022.
//

#include <iostream>
#include "quickhull.h"
#include "../utils/utils.h"

int distance(Point p1, Point p2, Point p) {
    return abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

void findhull(std::vector<Point> &ch, const std::vector<Point> &points, const Point &left, const Point &right) {
    int maxPointIndex = -1;
    int maxDistance = 0;

    // Find the farthest point from the line left-right
    for (int i = 0; i < points.size(); ++i) {
        int dist = distance(left, right, points[i]);
        if (dist > maxDistance) {
            maxPointIndex = i;
            maxDistance = dist;
        }
    }

    if (maxPointIndex == -1) {
        ch.push_back(left);
        return;
    }

    std::vector<Point> leftside;
    std::vector<Point> rightside;
    for (int i = 0; i < points.size(); ++i) {
        if (i == maxPointIndex) continue;

        int orienWithLeft = orientation(left, points[maxPointIndex], points[i]);
        if (orienWithLeft == CW) {
            leftside.push_back(points[i]);
        } else if (orientation(right, points[maxPointIndex], points[i]) == CCW) {
            rightside.push_back(points[i]);
        }
    }
    findhull(ch, leftside, left, points[maxPointIndex]);
    findhull(ch, rightside, points[maxPointIndex], right);
}

std::vector<Point> quickhull(const std::vector<Point> &points) {
    Point leftmost = get_leftmost_point(points);
    Point rightmost = get_rightmost_point(points);
    std::vector<Point> ch;
    std::vector<Point> rightside;
    std::vector<Point> leftside;

    // Split the points by the line from the leftmost to the rightmost
    for (Point point: points) {
        int orien = orientation(leftmost, rightmost, point);
        if (orien == CCW) { // this point is on the right of the line
            leftside.push_back(point);
        } else if (orien == CW) { // this point is on the left of the line
            rightside.push_back(point);
        }
    }

    findhull(ch, rightside, leftmost, rightmost);
    findhull(ch, leftside, rightmost, leftmost);

    return ch;
}