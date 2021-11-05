//
// Created by Domenico on 03/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_BST_H
#define COMPETITIVE_PROGRAMMING_BST_H

#include <vector>
#include <iostream>
#include "bst_inorder_iterator.h"

#define NO_ELEM -1

template<class ValTy, class Compare = std::less<ValTy>>
class bst {
public:
    using value_type = ValTy;
    using iterator = bst_inorder_iterator<value_type, Compare>;
    friend class bst_inorder_iterator<value_type, Compare>;

    /* constructors */
    bst() = default;
    bst(std::initializer_list<value_type>);

    /* methods */
    void insert(const value_type&);
    void clear();
    int size();
    const value_type& min();
    const value_type& max();
    bool contains(const value_type&);
    void print();

    /* iterators */
    iterator begin() { return iterator(&data, min_index); }
    iterator end()   { return iterator(&data, NO_ELEM); }

protected:
    struct bst_node {
        bst_node(const value_type &value, int parentIndex, int leftIndex, int rightIndex) :
            value(value), parent_index(parentIndex), left_index(leftIndex), right_index(rightIndex) {}
        const value_type &value;
        int parent_index;
        int left_index;
        int right_index;
    };
    Compare value_compare;
    std::vector<bst_node*> data;
    int max_index = NO_ELEM;
    int min_index = NO_ELEM;

private:
    void traversal_inorder(int current_index, void (*fun)(const value_type &));
};

#include "bst.tpp"

#endif //COMPETITIVE_PROGRAMMING_BST_H
