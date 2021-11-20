//
// Created by Domenico on 20/11/2021.
//

#include "towers.h"
#include <algorithm>

void towers(std::vector<int> &bars_len, int &largestHeight, int &totalTowers) {
    int height = 1;
    largestHeight = 0;
    totalTowers = 0;
    std::sort(bars_len.begin(),  bars_len.end());
    for(int i=0; i<bars_len.size(); ++i) {
        if (i+1 < bars_len.size() && bars_len[i] == bars_len[i+1]) {
            height++;
        } else {
            if (height > largestHeight) largestHeight = height;
            totalTowers++;
            height = 1;
        }
    }
}