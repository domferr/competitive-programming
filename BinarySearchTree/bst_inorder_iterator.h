//
// Created by Domenico on 04/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_BST_bst_inorder_iterator_H
#define COMPETITIVE_PROGRAMMING_BST_bst_inorder_iterator_H

#include <iterator>
#include <vector>
#include "bst.h"
#include "bst_utils.h"

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

    bst_inorder_iterator(std::vector<typename bst<Val, Compare>::bst_node> &data, int start_index) : data(data), current_index(start_index) {}

    reference operator*() const { return NODE_VALUE(data, current_index); }
    pointer operator->() const { return &(operator*()); }
    bst_inorder_iterator& operator++() {
        if (RIGHT_CHILDREN_INDEX(data, current_index) != NO_ELEM) {
            current_index = RIGHT_CHILDREN_INDEX(data, current_index);
            while (current_index != NO_ELEM && LEFT_CHILDREN_INDEX(data, current_index) != NO_ELEM) {
                current_index = LEFT_CHILDREN_INDEX(data, current_index);
            }
        } else {
            int last_index = current_index;
            current_index = PARENT_INDEX(data, current_index);
            while (current_index != NO_ELEM && last_index != LEFT_CHILDREN_INDEX(data, current_index)) {
                last_index = current_index;
                current_index = PARENT_INDEX(data, current_index);
            }
        }
        return *this;
    }
    friend bool operator== (const bst_inorder_iterator& a, const bst_inorder_iterator& b) { return a.current_index == b.current_index; };
    friend bool operator!= (const bst_inorder_iterator& a, const bst_inorder_iterator& b) { return a.current_index != b.current_index; };

private:
    std::vector<typename bst<Val, Compare>::bst_node> &data;
    int current_index;
};

#endif //COMPETITIVE_PROGRAMMING_BST_bst_inorder_iterator_H
