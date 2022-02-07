//
// Created by Domenico on 06/02/2022.
//

#include <iostream>
#include "kirkpatrick_seidel.h"
#define SLOPE(a, b) (a.x == b.x ? 100 : (double) ((a).y - (b).y)/((a).x - (b).x))

std::pair<Point, Point> upper_bridge_three_points(std::vector<Point> points, int med) {
    if (points[0].x > points[1].x) std::swap(points[0], points[1]);
    if (points[1].x > points[2].x) std::swap(points[1], points[2]);
    if (points[0].x > points[1].x) std::swap(points[0], points[1]);
    if (points[1].x < med)
        return points[0].y > points[1].y ? std::make_pair(points[0], points[2]):std::make_pair(points[1], points[2]);
    else
        return points[2].y > points[1].y ? std::make_pair(points[0], points[2]):std::make_pair(points[0], points[1]);
}

std::pair<Point, Point> upper_bridge(const std::vector<Point> &points, int med) {
    // handle simple and borderline cases
    if (points.size() == 2) return std::make_pair(points[0], points[1]);
    if (points.size() == 3) return upper_bridge_three_points(points, med);

    /*std::cout << "med: " << med << ", points: ";
    for(auto p: points) std::cout << p << " ";
    std::cout << std::endl;*/

    // compute the pairs and the avg slope
    int number_of_pairs = points.size() / 2;
    double slope_avg = 0;
    std::vector<std::pair<int, int>> pairs(points.size() / 2);
    for (int i = 0; i < points.size()-1; i += 2) {
        if (points[i].x < points[i+1].x)
            pairs[i/2] = std::make_pair(i, i+1);
        else
            pairs[i/2] = std::make_pair(i+1, i);
        slope_avg += SLOPE(points[pairs[i/2].first], points[pairs[i/2].second]);
        //std::cout << pairs[i/2].first << ", " << pairs[i/2].second << " " << SLOPE(points[pairs[i/2].first], points[pairs[i/2].second]) << std::endl;
    }
    std::vector<Point> remaining;
    if (points.size() % 2 == 1) {
        // one point is alone, count it but with a slope = 0
        number_of_pairs++;
        remaining.push_back(points.back());
    }
    slope_avg = slope_avg / number_of_pairs;
    /*std::cout << "avg: " << slope_avg << std::endl;
    std::flush(std::cout);*/

    // find max_c and top point
    double max_c = INT_MIN, c;
    Point top_point;
    for (auto pt: points) {
        // Given the point (xp, yp), y - yp = m(x - xp) => if x=0 then y = yp - m*xp
        c = pt.y - (slope_avg * pt.x);
        //std::cout << c << " ";
        if (c > max_c) {
            max_c = c;
            top_point = pt;
        }
    }
    /*std::cout << std::endl << max_c << " " << top_point << std::endl;
    std::flush(std::cout);*/

    // prune phase
    for (auto pair: pairs) {
        bool prune = false;
        if (top_point.x < med) {
            //std::cout << points[pair.first] << ", " << points[pair.second] << " " << SLOPE(points[pair.first], points[pair.second]) << std::endl;
            if (SLOPE(points[pair.first], points[pair.second]) >= slope_avg) {
                remaining.push_back(points[pair.second]);
                prune = true;
            }
        } else {
            if (SLOPE(points[pair.first], points[pair.second]) < slope_avg) {
                remaining.push_back(points[pair.first]);
                prune = true;
            }
        }
        if (!prune) {
            remaining.push_back(points[pair.first]);
            remaining.push_back(points[pair.second]);
        }
    }

    // recursive call
    /*std::cout << "remaining ";
    for (auto p: remaining) std::cout << p << " ";
    std::cout << std::endl;*/
    return upper_bridge(remaining, med);
}

std::vector<Point> kirkpatrick_seidel(std::vector<Point> &points) {
    int med = 0;
    for (auto p: points) med += p.x;
    med /= points.size();

    std::pair<Point, Point> up_br = upper_bridge(points, med);
    //std::cout << "upper bridge: " << up_br.first << ", " << up_br.second << std::endl;
    //std::flush(std::cout);
    std::vector<Point> left;
    std::vector<Point> right;
    for (auto p: points) {
        if (p.x <= up_br.first.x) left.push_back(p);
        else if (p.x >= up_br.second.x) right.push_back(p);
    }
    //std::cout << left.size() << ", " << right.size() << std::endl;
    std::vector<Point> left_hull;
    std::vector<Point> right_hull;

    if (left.size() > 2)
        left_hull = kirkpatrick_seidel(left);
    if (right.size() > 2)
        right_hull = kirkpatrick_seidel(right);

    std::vector<Point> finalhull;
    finalhull.reserve(left_hull.size() + right_hull.size() + 2);
    for (int i = right_hull.size() - 1; i >= 0; --i)
        finalhull.push_back(right_hull[i]);
    finalhull.push_back(up_br.second);
    for (int i = left_hull.size() - 1; i >= 0; --i)
        finalhull.push_back(left_hull[i]);
    return finalhull;
}

