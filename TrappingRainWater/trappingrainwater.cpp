//
// Created by Domenico on 28/10/2021.
//
// The problem:
// Given an array arr[] of N non-negative integers representing the height of blocks.
// If width of each block is 1, compute how much water can be trapped between the blocks
// during the rainy season.
// http://practice.geeksforgeeks.org/problems/trapping-rain-water/0
//

#include "trappingrainwater.h"

template<typename Iterator>
int trapped_rain_water(Iterator it, int& level) {
    if (*it > level) {
        level = *it;
    }
    return level - *it;
}

int trapping_rain_water(const std::vector<int>& vec) {
    auto begin = vec.begin();
    auto end = vec.end() - 1;
    int total_trapped_rain = 0;
    int current_elev = 0;

    while (begin != end) {
        if (*begin <= *end) {
            total_trapped_rain += trapped_rain_water(begin, current_elev);
            ++begin;
        } else {
            total_trapped_rain += trapped_rain_water(end, current_elev);
            --end;
        }
    }
    return total_trapped_rain;
}

int naive_trapping_rain_water(const std::vector<int>& vec) {
    int total = 0;

    for (size_t pos = 0; pos < vec.size(); ++pos) {
        int left_border = 0;
        size_t j = 0;
        while(j < pos) {
            if (vec.at(j) > left_border)
                left_border = vec.at(j);
            j++;
        }

        int right_border = 0;
        j = pos + 1;
        while(j < vec.size()) {
            if (vec.at(j) > right_border)
                right_border = vec.at(j);
            j++;
        }

        int minimum = std::min(left_border, right_border);
        if (minimum > vec.at(pos))
            total += minimum - vec.at(pos);
    }

    return total;
}