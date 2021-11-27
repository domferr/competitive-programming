//
// Created by Domenico on 27/11/2021.
//

#include "coin_change.h"

int coin_change(const int n, const std::vector<int> &coins) {
    std::vector<int> mat(n+1);
    mat[0] = 1;

    for(auto coin: coins) {
        for (int i = coin; i < mat.size(); ++i) {
            mat[i] += mat[i - coin];
        }
    }

    return mat.back();
}