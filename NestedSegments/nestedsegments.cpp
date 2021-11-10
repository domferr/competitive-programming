//
// Created by Domenico on 09/11/2021.
// The problem: You are given n segments on a line. There are no ends of some segments that coincide.
// For each segment find the number of segments it contains.
//

#include <set>
#include "nestedsegments.h"
#include "../FenwickTree/fenwicktree.h"

typedef std::pair<int, int> segment;

struct compare {
    // if two segments have the same starting position, then give precedence to the largest segment
    bool operator()(const std::pair<segment, int> &lhs, const std::pair<segment, int>  &rhs) const {
        segment leftSeg = lhs.first;
        segment rightSeg = rhs.first;
        if (leftSeg.first == rightSeg.first) {
            return leftSeg.second > rightSeg.second;
        }
        return leftSeg.first < rightSeg.first;
    }
};

std::vector<int> nested_segments(const std::vector<segment>& segments) {
    std::vector<int> res(segments.size());
    std::vector<int> end_positions(segments.size()); // end positions for each segment
    std::multiset<std::tuple<int, bool, int>> sorted_segments; // <pos, is end position, index of the segment in the vector>

    // remap segment[i] into <start, false, i> and <end, true, i>
    int i = 0;
    for (segment seg: segments) {
        auto start = std::make_tuple(seg.first, false, i);
        auto end = std::make_tuple(seg.second, true, i);
        sorted_segments.insert(start);
        sorted_segments.insert(end);
        i++;
    }

    // compute b
    std::vector<int> b(segments.size() * 2, 0); // init every value to 0
    i = 0;
    for (std::tuple<int, bool, int> elem: sorted_segments) {
        if (std::get<1>(elem)) { // is end point
            b[i] = 1;
            int seg_index = std::get<2>(elem);
            end_positions[seg_index] = i; // associate the segment to the end position
        } else {
            b[i] = 0;
        }
        i++;
    }

    // create the fenwick tree
    fenwicktree<int> ft(b);

    // prepare the sweepline algorithm
    std::multiset<std::pair<segment, int>, compare> sweepline; // <segment start pos, index of the segment in the vector>
    for (int j = 0; j < segments.size(); ++j) {
        sweepline.insert(std::make_pair(segments[j], j));
    }

    // process the segments from left to right by starting point
    for (const std::pair<segment, int>& seg: sweepline) {
        int seg_index = std::get<1>(seg);
        int endPos = end_positions[seg_index];
        ft.update(endPos, 0);
        int sum = ft.sum(endPos);
        res[seg_index] = sum;
    }

    return res;
}