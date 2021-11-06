//
// Created by Domenico on 05/11/2021.
// Problem: https://codeforces.com/contest/616/problem/D?locale=en
//

#include <map>
#include "longestkgoodsegment.h"

void longestkgoodsegment(const std::vector<int> &vec, int k, size_t *start_pointer, size_t *end_pointer) {
    int left_index = 0;
    int right_index = 0;
    int counter = 0;
    size_t largest_sub_array = 0;
    *start_pointer = 0;
    *end_pointer = 0;
    int value;
    std::map<int, int> occurrences {};

    while (right_index < vec.size()) {
        if (counter <= k) {
            value = vec[right_index];
            occurrences[value] += 1;
            if (occurrences[value] == 1)
                counter++;
            // keep track of the largest sub array
            if (counter <= k && right_index - left_index > largest_sub_array) {
                largest_sub_array = right_index - left_index;
                *start_pointer = left_index;
                *end_pointer = right_index;
            }

            right_index += 1;

        } else {
            value = vec[left_index];
            occurrences[value] -= 1;
            if (occurrences[value] == 0)
                counter--;
            left_index += 1;
        }
    }
}