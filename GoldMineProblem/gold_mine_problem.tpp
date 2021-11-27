//
// Created by Domenico on 27/11/2021.
//

#include "gold_mine_problem.h"

template<size_t rows, size_t cols>
int gold_mine(int (&matrix)[rows][cols]) {
    int result = 0;

    for (int j = 1; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (i == rows - 1) matrix[i][j] += std::max(matrix[i][j-1], matrix[i-1][j-1]);
            else if (i == 0) matrix[i][j] += std::max(matrix[i][j-1], matrix[i+1][j-1]);
            else matrix[i][j] += std::max({ matrix[i][j - 1], matrix[i - 1][j - 1], matrix[i + 1][j - 1] });

            if (j == cols - 1) result = std::max(result, matrix[i][j]);
        }
    }

    return result;
}
