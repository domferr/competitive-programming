//
// Created by Domenico on 28/10/2021.
//

#include <deque>
#include <iostream>
#include "nextlargerelement.h"

std::vector<int> nextlargerelement(std::vector<int> elements) {
    std::vector<int> next(elements.size());
    std::deque<int> Q;

    for (int i = 0; i < elements.size(); ++i) {

        while((!Q.empty()) && elements[i] > elements[Q.front()]) {
            next[Q.front()] = elements[i];
            Q.pop_front();
        }

        while((!Q.empty()) && elements[Q.back()] < elements[i]) {
            next[Q.back()] = elements[i];
            Q.pop_back();
        }

        Q.push_back(i);
    }

    while(!Q.empty()) {
        next[Q.back()] = -1;
        Q.pop_back();
    }
    
    return next;
}