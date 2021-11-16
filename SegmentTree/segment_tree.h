//
// Created by Domenico on 12/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_SEGMENT_TREE_H
#define COMPETITIVE_PROGRAMMING_SEGMENT_TREE_H

#include <vector>

template<class C>
class segment_tree {
public:
    using value_type = C;

    /* constructors */
    template<class It> segment_tree(It begin, It end, size_t size);
    segment_tree(const std::initializer_list<value_type> &list) : segment_tree(list.begin(),  list.end(), list.size()) {}
    segment_tree(const std::vector<value_type> &elements) : segment_tree(elements.begin(),  elements.end(), elements.size()) {}

    /* methods */
    C sum(size_t, size_t);
    C sum(size_t);
    void add(size_t, C);

    /* operators */
    C operator[](size_t);

private:
    std::vector<value_type> arr;
    struct range {
        range(size_t s, size_t e) : start(s), end(e) {}
        size_t start; size_t end;
    };
    template<class It> C build(size_t, range, It);
    C recursive_sum(size_t, range, range);
};

#include "segment_tree.tpp"

#endif //COMPETITIVE_PROGRAMMING_SEGMENT_TREE_H
