//
// Created by Domenico on 02/11/2021.
// The problem: Given a set of segments, where each segment is defined as a pair <start, end>, find a point where
// there are the largest number of intersections. If there are many, just report the leftmost.
// Target time: theta(nlogn) time
//

#include <set>
#include <iostream>
#include "maxsegmentintersections.h"

int max_segment_intersections(const std::vector<segment> &segments) {
    int max_seen = -1;
    int max_pos = -1;
    std::multiset<std::pair<int, bool>> multiset;
    for (segment seg: segments) {
        multiset.insert(std::make_pair(seg.start, false));
        multiset.insert(std::make_pair(seg.end, true));
    }

    int current_seen = 0;
    std::multiset<std::pair<int, bool>>::iterator it;
    for(it=multiset.begin(); it != multiset.end(); ++it) {
        if (it->second)
            current_seen--;
        else
            current_seen++;
        if (current_seen > max_seen) {
            max_pos = it->first;
            max_seen = current_seen;
        }
    }
    return max_pos;
}