//
// Created by Domenico on 09/11/2021.
//

#include <iostream>
#include "fenwicktree.h"

#define PARENT_INDEX(idx) (idx - (idx & -idx))
#define RIGHT_SIBLING_INDEX(idx) (idx + (idx & -idx))
#define IS_NOT_ROOT(idx) (idx != 0)

template<class C>
template<class It>
fenwicktree<C>::fenwicktree(It first, It last, size_t size) : data(size + 1) {
    size_t idx = 1;
    for (auto it = first; it != last; ++it) {
        data[idx] = *it;
        idx++;
    }

    for (idx = 1; RIGHT_SIBLING_INDEX(idx) < data.size(); ++idx) {
        data[RIGHT_SIBLING_INDEX(idx)] += data[idx];
    }
}

template<class C>
fenwicktree<C>::fenwicktree(size_t size, C starting_value) : data(size + 1, starting_value) {
    for (size_t idx = 1; RIGHT_SIBLING_INDEX(idx) < data.size(); ++idx) {
        data[RIGHT_SIBLING_INDEX(idx)] += data[idx];
    }
}

template<class C>
C fenwicktree<C>::sum(size_t index) {
    index = index + 1;
    C s = data[index]; // just a trick to avoid initializing s to 0
    index = PARENT_INDEX(index);
    while(IS_NOT_ROOT(index)) {
        s += data[index];
        index = PARENT_INDEX(index);
    }

    return s;
}

template<class C>
C fenwicktree<C>::rangesum(size_t start_idx, size_t end_idx) {
    if (start_idx == 0)
        return sum(end_idx);
    // here start_idx - 1 is >= 0
    return sum(end_idx) - sum(start_idx - 1);
}

template<class C>
void fenwicktree<C>::add(size_t index, C value) {
    index = index + 1;
    while (index <= data.size()) {
        data[index] += value;
        index = RIGHT_SIBLING_INDEX(index);
    }
}


template<class C>
void fenwicktree<C>::update(size_t index, C value) {
    C old_val = operator[](index);
    add(index, value - old_val);
}

template<class C>
size_t fenwicktree<C>::size() {
    return data.size() - 1;
}

template<class C>
C fenwicktree<C>::operator[](size_t index) {
    if (index == 0)
        return sum(index);
    return sum(index) - sum(index - 1);
}
