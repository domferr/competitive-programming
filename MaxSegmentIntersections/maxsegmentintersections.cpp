//
// Created by Domenico on 02/11/2021.
// The problem: Given a set of segments, where each segment is defined as a pair <start, end>, find a point where
// there are the largest number of intersections. If there are many, just report the leftmost.
// Target time: theta(nlogn) time
//

#include <map>
#include <iostream>
#include "maxsegmentintersections.h"

int max_segment_intersections(const std::vector<segment> &segments) {
    int max_seen = -1;
    int max_pos = -1;
    std::map<int, bool> map;
    for (segment seg: segments) {
        map.insert(std::make_pair(seg.start, false));
        map.insert(std::make_pair(seg.end, true));
    }

    int current_seen = 0;
    std::map<int, bool>::iterator it;
    for(it=map.begin(); it!=map.end(); ++it) {
        if (it->second)
            current_seen--;
        else
            current_seen++;
        if (current_seen > max_seen) {
            max_pos = it->first;
            max_seen = current_seen;
        }
        std::cout << it->first << " => " << it->second << std::endl;
    }
    return max_pos;
}