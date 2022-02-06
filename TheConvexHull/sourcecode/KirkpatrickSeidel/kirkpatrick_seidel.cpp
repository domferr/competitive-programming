//
// Created by Domenico on 06/02/2022.
//

#include <iostream>
#include <math.h>
#include "kirkpatrick_seidel.h"
#define SLOPE(a, b) (a.x == b.x ? 100 : (a.y - b.y)/(a.x - b.x))

std::vector<Point> ch_three_points(const std::vector<Point> &points) {
    int orien = orientation(points[0], points[1], points[2]);
    if (orien == COL) return { points[0], points[2] };
    if (orien == CCW) return { points[0], points[1], points[2] };
    return { points[0], points[2], points[1] };
}

std::pair<Point, Point> upper_bridge(const std::vector<Point> &points, int med) {
    if (points.size() == 2) return std::make_pair(points[0], points[1]);

    // compute the pairs and the avg slope
    int slope_avg = 0;
    std::vector<std::pair<int, int>> pairs(points.size() / 2);
    for (int i = 0; i < points.size(); i += 2) {
        pairs.push_back(std::make_pair(i, i+1));
        slope_avg += SLOPE(points[i], points[i+1]);
    }
    slope_avg = slope_avg / (int)pairs.size();
    std::cout << slope_avg << std::endl;
    std::flush(std::cout);

    // find max_c and top point
    int max_c = INT_MIN;
    int top_point;
    for (auto pair: pairs) {
        // y = mx + c => c = y - mx
        int c = points[pair.first].y - slope_avg * points[pair.first].x;
        if (c > max_c) {
            max_c = c;
            top_point = pair.first;
        }
        c = points[pair.second].y - slope_avg * points[pair.second].x;
        if (c > max_c) {
            max_c = c;
            top_point = pair.second;
        }
    }
    std::cout << max_c << " " << points[top_point] << std::endl;
    std::flush(std::cout);

    // cut the points
    std::vector<Point> remaining;
    for (auto pair: pairs) {
        if (points[top_point].x < med) {
            if (SLOPE(points[pair.first], points[pair.second]) >= slope_avg)
                remaining.push_back(points[pair.first]);
        } else if (SLOPE(points[pair.first], points[pair.second]) < slope_avg) {
            remaining.push_back(points[pair.second]);
        }
    }

    // recursive call
    std::cout << "recursive call " << remaining.size() << std::endl;
    std::flush(std::cout);
    return upper_bridge(remaining, med);
}

std::vector<Point> kirkpatrick_seidel(const std::vector<Point> &points) {
    if (points.size() == 3) return ch_three_points(points);
    
    int med = 0;
    for (auto p: points) med += p.x;
    med /= points.size();

    std::pair<Point, Point> up_br = upper_bridge(points, med);
    std::vector<Point> left;
    std::vector<Point> right;
    for (auto p: points) {
        if (p.x <= up_br.first.x) left.push_back(p);
        else if (p.x >= up_br.second.x) right.push_back(p);
    }
    std::vector<Point> left_hull = kirkpatrick_seidel(left);
    std::vector<Point> right_hull = kirkpatrick_seidel(right);

    std::vector<Point> finalhull;
    finalhull.reserve(left_hull.size() + right_hull.size() + 2);
    for (int i = right_hull.size() - 1; i >= 0; --i)
        finalhull.push_back(right_hull[i]);
    finalhull.push_back(up_br.second);
    finalhull.push_back(up_br.first);
    for (int i = left_hull.size() - 1; i >= 0; --i)
        finalhull.push_back(left_hull[i]);
    return finalhull;
}

