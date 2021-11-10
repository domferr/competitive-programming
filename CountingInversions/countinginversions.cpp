//
// Created by Domenico on 10/11/2021.
// The problem: Inversion Count for an array indicates – how far (or close) the array is from being sorted.
// If the array is already sorted, then the inversion count is 0, but if the array is sorted
// in the reverse order, the inversion count is the maximum. Formally speaking, two elements
// a[i] and a[j] form an inversion if a[i] > a[j] and i < j
//

#include <algorithm>
#include <map>
#include "countinginversions.h"
#include "../FenwickTree/fenwicktree.h"

int counting_inversions_ft(const std::vector<int> &vec) {
    // sort the elements
    std::multimap<int, int> sorted;
    typedef std::pair<int, int> int_pair;
    for (int i = 0; i < vec.size(); ++i) {
        sorted.insert(int_pair(vec[i], i));
    }

    // remap the values with each ranking in the sorted array
    std::vector<int> ranking_remap(sorted.size());
    int i = 0;
    for (int_pair item : sorted) {
        int old_pos = item.second;
        ranking_remap[old_pos] = i;
        i++;
    }

    // create fenwick tree
    fenwicktree<int> ft(vec.size(), 0);

    // scan elements from right to left
    int counter = 0;
    for (int j = ranking_remap.size() - 1; j >= 0; --j) {
        int rank = ranking_remap[j];
        if (rank > 0) counter += ft.sum(rank - 1);
        ft.update(rank, 1);
    }

    return counter;
}