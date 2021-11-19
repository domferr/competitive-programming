//
// Created by Domenico on 19/11/2021.
//

#include <queue>
#include "rodcutting.h"

int rodcutting(const std::vector<int> &prices) {
    std::vector<int> costs(prices.size() + 1, 0); // add the fake destination as last position

    for (int i = 0; i < prices.size(); ++i) {
        for (int j = i + 1; j <= prices.size(); ++j) {
            int pij = prices[j - i - 1];
            if (costs[j] < costs[i] + pij)
                costs[j] = costs[i] + pij;
        }
    }

    return costs[prices.size()]; // the solution is the final total cost got at the fake destination
}
