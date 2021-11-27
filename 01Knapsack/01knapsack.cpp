//
// Created by Domenico on 27/11/2021.
//

#include "01knapsack.h"

#define ITEM_SIZE(item) (item).first
#define ITEM_VALUE(item) (item).second

int zero_one_knapsack(const std::vector<item> &items, int max_capacity) {
    int rows = items.size();
    int columns = max_capacity + 1;
    int *M = new int[ rows * columns ];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == 0)
                M[i * columns + j] = ITEM_SIZE(items[i]) <= j ? ITEM_VALUE(items[i]):0;
            else if (j == 0)
                M[i * columns + j] = 0;
            else if (j - ITEM_SIZE(items[i]) < 0)
                M[i * columns + j] = M[((i-1) * columns) + j];
            else
                M[i * columns + j] = std::max(M[((i-1) * columns) + j], M[((i-1) * columns) + j - ITEM_SIZE(items[i])] + ITEM_VALUE(items[i]));
        }
    }

    int solution = M[((rows - 1) * columns) + columns - 1];
    delete[] M;
    return solution;
}