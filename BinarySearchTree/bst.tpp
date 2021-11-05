//
// Created by Domenico on 03/11/2021.
//

#include "bst.h"
#include "bst_inorder_iterator.h"
#include "bst_utils.h"

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
        bool valueIsLess = value_compare(value, NODE_VALUE(data, i));
        next_index = valueIsLess ? LEFT_CHILDREN_INDEX(data, i) : RIGHT_CHILDREN_INDEX(data, i);
        if (next_index == NO_ELEM) {
            parent_index = i;
            if (valueIsLess)
                LEFT_CHILDREN_INDEX(data, i) = data.size();
            else
                RIGHT_CHILDREN_INDEX(data, i) = data.size();
        }
        i = next_index;
    }
    if (min_index == NO_ELEM || value_compare(value, NODE_VALUE(data, min_index)))
        min_index = data.size();
    if (max_index == NO_ELEM || value_compare(NODE_VALUE(data, max_index), value))
        max_index = data.size();

    data.push_back(bst_node(value, parent_index, NO_ELEM, NO_ELEM));
}

template<class C, class CMP>
int bst<C, CMP>::size() {
    return data.size();
}

template<class C, class CMP>
const C& bst<C, CMP>::min() {
    if (data.empty()) throw std::exception("min called with empty tree");

    return NODE_VALUE(data, min_index);
}

template<class C, class CMP>
const C& bst<C, CMP>::max() {
    if (data.empty()) throw std::exception("max called with empty tree");

    return NODE_VALUE(data, max_index);
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
        if (NODE_VALUE(data, i) == v)
            return true;
        if (value_compare(v, NODE_VALUE(data, i)))
            i = LEFT_CHILDREN_INDEX(data, i);
        else
            i = RIGHT_CHILDREN_INDEX(data, i);
    }

    return false;
}