//
// Created by Domenico on 09/11/2021.
//

#include <iostream>
#include "fenwicktree.h"

#define PARENT_INDEX(idx) (idx - (idx & -idx))
#define RIGHT_SIBLING_INDEX(idx) (idx + (idx & -idx))
#define IS_NOT_ROOT(idx) (idx != 0)

template<class It>
fenwicktree::fenwicktree(It first, It last)  : data((last - first) + 1) {
    size_t idx = 1;
    for (auto it = first; it != last; ++it) {
        data[idx] = *it;
        idx++;
    }

    for (idx = 1; RIGHT_SIBLING_INDEX(idx) < data.size(); ++idx) {
        data[RIGHT_SIBLING_INDEX(idx)] += data[idx];
    }
}

int fenwicktree::sum(size_t index) {
    int s = 0;
    index = index + 1;
    while(IS_NOT_ROOT(index)) {
        s += data[index];
        index = PARENT_INDEX(index);
    }
    return s;
}

int fenwicktree::rangesum(size_t start_idx, size_t end_idx) {
    if (start_idx == 0)
        return sum(end_idx);
    // here start_idx - 1 is >= 0
    return sum(end_idx) - sum(start_idx - 1);
}

void fenwicktree::add(size_t index, int value) {
    while (index <= data.size()) {
        data[index] += value;
        index = RIGHT_SIBLING_INDEX(index);
    }
}

size_t fenwicktree::size() {
    return data.size() - 1;
}

int fenwicktree::operator[](size_t index) {
    if (index == 0)
        return sum(index);
    return sum(index) - sum(index - 1);
}
