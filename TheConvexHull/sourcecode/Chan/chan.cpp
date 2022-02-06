//
// Created by Domenico on 06/02/2022.
//

#include <complex>
#include <iostream>
#include "chan.h"
#include "../GrahamScan/grahamscan.h"

Point next_candidate(const std::vector<Point> &subhull, const Point &last) {
    unsigned int curr = 0, inc = subhull.size()/2, next, prev;
    Point next_point = subhull[0];
    bool found = false;
    while(!found) {
        next = (curr + 1) % subhull.size();
        prev = (curr - 1) % subhull.size();
        if (orientation(last, subhull[curr], subhull[next]) == CW) {
            curr = (curr + inc) % subhull.size();
        } else if (orientation(last, subhull[curr], subhull[prev]) == CW) {
            curr = (curr - inc) % subhull.size();
        } else {
            next_point = subhull[curr];
            found = true;
        }
        if (inc > 2) inc /= 2;
    }

    return next_point;
}

std::vector<Point> chan(const std::vector<Point> &points, int m, int h) {
    unsigned int subset_size = std::round((double) points.size() / m);
    std::vector<std::vector<Point>> pts(m);
    std::vector<std::vector<Point>> ch(m);
    // subdivide points into m subsets
    int j = 0;
    for (int i = 1; i <= points.size(); ++i) {
        pts[j].push_back(points[i-1]);
        if (i % subset_size == 0 && j + 1 < m)
            j++;
    }

    // graham scan for each subhull
    for (int i = 0; i < m; ++i) ch[i] = grahamscan(pts[i]);

    std::vector<Point> finalhull { rightmost_point(points) };
    for (int k = 0; k < h; ++k) {
        Point best{ INT_MIN, INT_MIN };
        // jarvis march phase
        for (int i = 0; i < m; ++i) {
            // do not compare last point with itself when the set has only the last point
            if (ch[i].size() == 1 && ch[i][0] == finalhull.back()) continue;
            // find the next candidate via binary search and compare with the best found
            Point next = next_candidate(ch[i], finalhull.back());
            if (best == Point{ INT_MIN, INT_MIN } ||
                orientation(finalhull.back(), best, next) == CW)
                best = next;
        }

        if (best == finalhull[0]) return finalhull;
        finalhull.push_back(best);
    }

    return {};
}

std::vector<Point> chan(const std::vector<Point> &points) {
    int m, t = 1;
    std::vector<Point> ch;
    do {
        m = std::min((int)std::pow(2, std::pow(2, t)), (int)points.size());
        ch = chan(points, m, m);
        t++;
    } while(ch.empty());

    return ch;
}