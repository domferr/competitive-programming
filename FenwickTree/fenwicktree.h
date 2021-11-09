//
// Created by Domenico on 09/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_FENWICKTREE_H
#define COMPETITIVE_PROGRAMMING_FENWICKTREE_H

#include <vector>

template <class C> // Class C must support the following operators: -, +=, ==
class fenwicktree {
private:
    std::vector<C> data;

public:
    /* Constructors */
    fenwicktree() = default;
    explicit fenwicktree(size_t n) : data(n+1) {}
    template<class It> fenwicktree(It, It);
    fenwicktree(std::initializer_list<C> list) : fenwicktree(list.begin(), list.end()) {}
    explicit fenwicktree(const std::vector<C>& vec) : fenwicktree(vec.begin(), vec.end()) {}

    /* Methods */
    C sum(size_t);
    C rangesum(size_t, size_t);
    void add(size_t, C);
    size_t size();

    /* Operators */
    C operator[](size_t);
};

#include "fenwicktree.tpp"

#endif //COMPETITIVE_PROGRAMMING_FENWICKTREE_H
