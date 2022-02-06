//
// Created by Domenico on 05/02/2022.
//

#include <algorithm>
#include "incremental.h"
#include "../utils/utils.h"

std::vector<Point> incremental(std::vector<Point> points) {
    // Sort points by x-coordinate or by y-coordinate if there is a tie
    std::sort(points.begin(), points.end(), [](Point &p1, Point &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    });
    std::vector<std::pair<int, int>> adj(3);
    // init the adjacency vector in counter-clockwise order
    if (orientation(points[0], points[1], points[2]) == CCW)
        adj = { {1, 2}, {1, 0}, {0, 1} }; // order is 0 -> 1 -> 2
    else
        adj = { {2, 1}, {0, 2}, {1, 0} }; // order is 0 -> 2 -> 1

    int t1, t2, curr, next;
    for (int i = 3; i < points.size(); ++i) {
        // find the transition points t1 and t2
        curr = i-1;
        next = adj[i-1].first;
        while(orientation(points[i], points[curr], points[next]) == CW) {
            curr = next;
            next = adj[next].first;
        }
        t1 = curr;
        curr = i-1;
        next = adj[i-1].second;
        while(orientation(points[i], points[curr], points[next]) == CCW) {
            curr = next;
            next = adj[next].second;
        }
        t2 = curr;
        // remove points between t1 and t2
        adj[t2].first = i;
        adj[t1].second = i;
        // add current point between t1 and t2
        adj[i].first = t1;
        adj[i].second = t2;
    }
    // compute the convex hull vector from the adjacency vector
    std::vector<Point> ch;
    int i = 0;
    do {
        ch.push_back(points[i]);
        i = adj[i].first;
    } while(i != 0);

    return ch;
}
