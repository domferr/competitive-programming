//
// Created by Domenico on 03/11/2021.
//

#include "bst.h"
#include "bst_inorder_iterator.h"

template<class ValTy, class Compare>
bst<ValTy, Compare>::bst(std::initializer_list<ValTy> list) {
    for (const value_type& value:list) {
        insert(value);
    }
}

template<class C, typename Compare>
void bst<C, Compare>::insert(const value_type &value) {
    int i = 0;
    int next_index = 0;
    int parent_index = NO_ELEM;

    while(i != NO_ELEM && i < data.size()) {
        bool valueIsLess = value_compare(value, data[i]->value);
        next_index = valueIsLess ? data[i]->left_index : data[i]->right_index;
        if (next_index == NO_ELEM) {
            parent_index = i;
            if (valueIsLess)
                data[i]->left_index = data.size();
            else
                data[i]->right_index = data.size();
        }
        i = next_index;
    }
    if (min_index == NO_ELEM || value_compare(value, data[min_index]->value))
        min_index = data.size();
    if (max_index == NO_ELEM || value_compare(data[max_index]->value, value))
        max_index = data.size();
    auto *newNode = new bst_node(value, parent_index, NO_ELEM, NO_ELEM);
    data.push_back(newNode);
}

template<class C, class CMP>
int bst<C, CMP>::size() {
    return data.size();
}

template<class C, class CMP>
const C& bst<C, CMP>::min() {
    if (data.empty()) throw std::exception("min called with empty tree");

    return data[min_index]->value;
}

template<class C, class CMP>
const C& bst<C, CMP>::max() {
    if (data.empty()) throw std::exception("max called with empty tree");

    return data[max_index]->value;
}

template<class C, class CMP>
void bst<C, CMP>::clear() {
    data.clear();
}

template<class C, class CMP>
bool bst<C, CMP>::contains(const value_type &v) {
    if (data.empty()) return false;
    int i = 0;

    while (i < data.size()) {
        if (data[i]->value == v)
            return true;
        if (value_compare(v, data[i]->value))
            i = data[i]->left_index;
        else
            i = data[i]->right_index;
    }

    return false;
}

template <class Val, class Compare>
void bst<Val, Compare>::traversal_inorder(int current_index, void (*fun)(const value_type &)) {
    if (current_index != NO_ELEM) {
        bst_node *curr = data[current_index];
        traversal_inorder(curr->left_index, fun);
        fun(curr->value);
        traversal_inorder(curr->right_index, fun);
    }
}

template <class Val>
void print_fun(const Val &val) {
    std::cout << val << " " << std::endl;
}

template <class Val, class Compare>
void bst<Val, Compare>::print() {
    traversal_inorder(0, &print_fun<Val>);
    std::cout << "FINE" << std::endl;
}