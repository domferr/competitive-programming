//
// Created by Domenico on 27/11/2021.
//

#include "tiling_problem.h"

#include <vector>

int tiling_problem(int n) {
    std::vector<int> m(n);

    for (int i = 0; i < m.size(); ++i) {
        if (i > 2)
            m[i] = m[i-1] + m[i-2];
        else
            m[i] = i;
    }

    return m.back();
}