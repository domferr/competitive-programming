//
// Created by Domenico on 19/11/2021.
//

#include <iostream>
#include "houserobber.h"

#define HANDLE_EDGE(from, to, costs, revenues) \
    if (to < revenues.size() && costs[to] < costs[from] + revenues[to]) {    \
        costs[to] = costs[from] + revenues[to];      \
    }

int houserobber(const std::vector<int> &revenues) {
    std::vector<int> costs(revenues.begin(),  revenues.end());
    int solution = 0;

    for (int i = 0; i < revenues.size(); ++i) {
        HANDLE_EDGE(i, i + 2, costs, revenues)
        HANDLE_EDGE(i, i + 3, costs, revenues)

        if (solution < costs[i]) {
            solution = costs[i];
        }
    }

    return solution;
}