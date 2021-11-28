//
// Created by Domenico on 28/11/2021.
//

#include "subset_sum.h"

bool subset_sum(const std::vector<int> &arr, int sum) {
    int rows = arr.size() + 1;
    int cols = sum + 1;
    bool *mat = new bool[rows * cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j == 0) mat[i * cols + j] = true;
            else if (i == 0) mat[i * cols + j] = false;
            else if (j - arr[i - 1] >= 0) mat[i * cols + j] = mat[(i-1) * cols + j] || mat[(i - 1) * cols + j - arr[i - 1]];
            else mat[i * cols + j] = mat[(i-1) * cols + j];
        }
    }

    return mat[(rows - 1) * cols + (cols - 1)];
}