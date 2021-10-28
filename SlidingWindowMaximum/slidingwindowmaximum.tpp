//
// Created by Domenico on 28/10/2021.
//
// The problem:
// Given an array arr[] of N elements and integer K, find the maximum for each and every contiguous subarray (window)
// of size K.
// From: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
//

#include "slidingwindowmaximum.h"
#include <deque>

template<typename T>
std::vector<T> slidingwindowmax(const std::vector<T>& vector, const int& k) {
    std::deque<int> Q;
    std::vector<int> out;
    out.reserve(vector.size() - k + 1);

    for (int i = 0; i < vector.size(); ++i) {
        // remove from the front the elements that are no longer in the window
        while((!Q.empty()) && Q.front() <= i - k) {
            Q.pop_front();
        }
        // remove from back the elements that are no longer useful because they are not grater than the current element
        while((!Q.empty()) && vector[i] >= vector[Q.back()]) {
            Q.pop_back();
        }
        // insert the new element
        Q.push_back(i);

        if (i >= k-1)
            out.push_back(vector[Q.front()]);
    }

    return out;
}