//
// Created by Domenico on 21/11/2021.
//

#include "minimum_cost_path.h"

template <size_t rows, size_t cols>
int minimum_cost_path(const int (&matrix)[rows][cols]) {
    int minCost[rows][cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            minCost[i][j] = matrix[i][j];
            if (j - 1 >= 0 && i - 1 >= 0)
                minCost[i][j] += std::min(minCost[i][j-1], minCost[i-1][j]);
            else if (j - 1 >= 0)
                minCost[i][j] += minCost[i][j-1];
            else if (i - 1 >= 0)
                minCost[i][j] += minCost[i-1][j];
        }
    }

    return minCost[rows - 1][cols - 1];
}