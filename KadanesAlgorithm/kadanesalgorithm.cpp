//
// Created by Domenico on 19/11/2021.
//

#include "kadanesalgorithm.h"

int kadanesalgorithm(const std::vector<int> &numbers) {
    int maxSum = 0;
    for(auto num: numbers) {
        maxSum += num;
    }
    size_t i = 0;
    size_t j = numbers.size() - 1;
    int currentSum = maxSum;
    while(i < j) {
        if (numbers[i] < numbers[j]) {
            currentSum -= numbers[i];
            ++i;
        } else {
            currentSum -= numbers[j];
            --j;
        }
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}
