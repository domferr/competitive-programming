//
// Created by Domenico on 04/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_BST_bst_inorder_iterator_H
#define COMPETITIVE_PROGRAMMING_BST_bst_inorder_iterator_H

#include <iterator>
#include <vector>
#include "bst.h"
#define NO_ELEM -1

template<class ValTy, class Compare> class bst;

template<typename Val, class Compare>
class bst_inorder_iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = Val;
    using pointer           = Val*;
    using reference         = const Val&;

    bst_inorder_iterator(std::vector<typename bst<Val, Compare>::bst_node*> *d, int start_index) : data(d), current_index(start_index) {}

    reference operator*() const { return (*data)[current_index]->value; }
    pointer operator->() const { return (*data)[current_index].value; /* &(operator*()); */ }
    bst_inorder_iterator& operator++() {
        if ((*data)[current_index]->right_index != NO_ELEM) {
            current_index = (*data)[current_index]->right_index;
            while (current_index != NO_ELEM && (*data)[current_index]->left_index != NO_ELEM) {
                current_index = (*data)[current_index]->left_index;
            }
        } else {
            int last_index = current_index;
            current_index = (*data)[current_index]->parent_index;
            while (current_index != NO_ELEM && last_index != (*data)[current_index]->left_index) {
                last_index = current_index;
                current_index = (*data)[last_index]->parent_index;
            }
        }
        return *this;
    }
    friend bool operator== (const bst_inorder_iterator& a, const bst_inorder_iterator& b) { return a.current_index == b.current_index; };
    friend bool operator!= (const bst_inorder_iterator& a, const bst_inorder_iterator& b) { return a.current_index != b.current_index; };

private:
    std::vector<typename bst<Val, Compare>::bst_node*> *data;
    int current_index;
};

#endif //COMPETITIVE_PROGRAMMING_BST_bst_inorder_iterator_H
