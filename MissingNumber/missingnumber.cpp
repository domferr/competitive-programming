//
// Created by Domenico on 19/11/2021.
//

#include "missingnumber.h"
#include <numeric>

size_t missingnumber(const std::vector<int> &numbers) {
    size_t n = numbers.size() + 1;
    size_t maxsum = (n * (n + 1)) / 2;
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    return maxsum - sum;
}