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
    std::vector<value_type> heap;
    size_t max_segment_end; // needed to left balance the tree
    C recursive_sum(size_t, size_t, size_t, size_t, size_t);
    C rec_constr(size_t, size_t, size_t, size_t);
};

#include "segment_tree.tpp"

#endif //COMPETITIVE_PROGRAMMING_SEGMENT_TREE_H
