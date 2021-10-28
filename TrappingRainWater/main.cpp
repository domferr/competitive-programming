//
// Created by Domenico on 28/10/2021.
//

#include <iostream>
#include "trappingrainwater.h"

int main() {
    std::vector<int> vector;
    size_t n;
    // Read the amount of elements
    std::cin >> n;
    // Reserve enough space because we know the vector size beforehand
    vector.reserve(n);
    // Read n elements
    for (size_t i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        vector.push_back(x);
    }
    //Run the algorithm
    int total_trapped_water = trapping_rain_water(vector);
    std::cout << total_trapped_water;

    return 0;
}