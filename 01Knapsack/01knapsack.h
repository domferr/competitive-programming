//
// Created by Domenico on 27/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_01KNAPSACK_H
#define COMPETITIVE_PROGRAMMING_01KNAPSACK_H

#include <vector>

typedef std::pair<int, int> item;
#define ITEM(size, value) std::make_pair(size, value)

int zero_one_knapsack(const std::vector<item> &items, int max_capacity);

#endif //COMPETITIVE_PROGRAMMING_01KNAPSACK_H
