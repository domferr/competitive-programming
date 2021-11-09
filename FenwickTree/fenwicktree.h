//
// Created by Domenico on 09/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_FENWICKTREE_H
#define COMPETITIVE_PROGRAMMING_FENWICKTREE_H

#include <vector>

class fenwicktree {
private:
    std::vector<int> data;

public:
    /* Constructors */
    fenwicktree() = default;
    explicit fenwicktree(size_t n) : data(n+1) {}
    template<class It> fenwicktree(It first, It last);
    fenwicktree(std::initializer_list<int> list) : fenwicktree(list.begin(), list.end()) {}
    explicit fenwicktree(const std::vector<int>& vec) : fenwicktree(vec.begin(), vec.end()) {}

    /* Methods */
    int sum(size_t);
    int rangesum(size_t, size_t);
    void add(size_t, int);
    size_t size();

    /* Operators */
    int operator[](size_t);
};

#include "fenwicktree.tpp"

#endif //COMPETITIVE_PROGRAMMING_FENWICKTREE_H
