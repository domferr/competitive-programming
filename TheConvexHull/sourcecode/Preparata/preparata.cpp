//
// Created by Domenico on 05/02/2022.
//

#include <iostream>
#include "preparata.h"
#include "../utils/utils.h"

std::vector<Point> ch_three_points(const Point &a, const Point &b, const Point &c) {
    int orien = orientation(a, b, c);
    if (orien == COL) return { a, c };
    if (orien == CCW) return { a, b, c };
    return { a, c, b };
}

std::pair<int, int> upper_bridge(const std::vector<Point> &ch1, int ind_ch1, const std::vector<Point> &ch2, int ind_ch2) {
    bool done = false;
    int next_ind2 = (ch2.size() + ind_ch2 - 1) % ch2.size();
    int next_ind1 = (ind_ch1 + 1) % ch1.size();
    while(!done) {
        done = true;
        while(orientation(ch2[ind_ch2], ch1[ind_ch1], ch1[next_ind1]) == CW) {
            ind_ch1 = next_ind1;
            next_ind1 = (next_ind1 + 1) % ch1.size();
        }

        while(orientation(ch1[ind_ch1], ch2[ind_ch2], ch2[next_ind2]) == CCW) {
            ind_ch2 = next_ind2;
            next_ind2 = (ch2.size() + next_ind2 - 1) % ch2.size();
            done = false;
        }
    }

    return std::make_pair(ind_ch1, ind_ch2);
}

std::pair<int, int> lower_bridge(const std::vector<Point> &ch1, int ind_ch1, const std::vector<Point> &ch2, int ind_ch2) {
    bool done = false;
    while(!done) {
        done = true;
        while(orientation(ch1[ind_ch1], ch2[ind_ch2], ch2[(ind_ch2+1)%ch2.size()]) == CW)
            ind_ch2 = (ind_ch2+1) % ch2.size();

        while(orientation(ch2[ind_ch2], ch1[ind_ch1], ch1[(ch1.size()+ind_ch1-1)%ch1.size()]) == CCW) {
            ind_ch1 = (ch1.size() + ind_ch1 - 1) % ch1.size();
            done = false;
        }
    }
    return std::make_pair(ind_ch1, ind_ch2);
}

std::vector<Point> merge(const std::vector<Point> &ch1, const std::vector<Point> &ch2) {
    int ch1_rightmost_index = rightmost_point_index(ch1);
    int ch2_leftmost_index = leftmost_point_index(ch2);
    // compute upper bridge
    std::pair<int, int> up_bridge = upper_bridge(ch1, ch1_rightmost_index, ch2, ch2_leftmost_index);
    // compute lower bridge
    std::pair<int, int> lo_bridge = lower_bridge(ch1, ch1_rightmost_index, ch2, ch2_leftmost_index);
    // merge the subhulls
    std::vector<Point> ch_merged;
    ch_merged.push_back(ch1[up_bridge.first]);
    int i = up_bridge.first;
    while (i != lo_bridge.first) {
        i = (i+1) % ch1.size();
        ch_merged.push_back(ch1[i]);
    }

    ch_merged.push_back(ch2[lo_bridge.second]);
    i = lo_bridge.second;
    while (i != up_bridge.second) {
        i = (i+1) % ch2.size();
        ch_merged.push_back(ch2[i]);
    }

    return ch_merged;
}

std::vector<Point> preparata(std::vector<Point> &points, int l, int r) {
    if (r - l == 1) return { points[l] };
    if (r - l == 2) return { points[l], points[l+1] };
    if (r - l == 3) return ch_three_points(points[l], points[l+1], points[l+2]);

    int m = (l+r) / 2;
    std::vector<Point> ch1 = preparata(points, l, m);
    std::vector<Point> ch2 = preparata(points, m, r);

    return merge(ch1, ch2);
}