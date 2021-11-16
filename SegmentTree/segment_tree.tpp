//
// Created by Domenico on 12/11/2021.
//

#include "segment_tree.h"

// Ranges
#define MIDDLE_OF_RANGE(ran) (((ran).end + (ran).start) / 2)
#define LEFT_SUB_RANGE(ran) range( (ran).start, MIDDLE_OF_RANGE(ran) )
#define RIGHT_SUB_RANGE(ran) range( MIDDLE_OF_RANGE(ran) + 1, (ran).end )
#define MAX_RANGE(arr) range(0, (arr.size() - 1) / 2)

// Nodes indexes in the array (in the order of euler tour traversal)
#define LEFT_CHILD_IDX(idx) ((idx) + 1)
#define RIGHT_CHILD_IDX(idx, ran) ((idx) + (2 * (MIDDLE_OF_RANGE(ran) - (ran).start + 1)))
#define ROOT_IDX 0

template<class C>
template<class It>
C segment_tree<C>::build(size_t pos, range curr_range, It it) {
    if (curr_range.start == curr_range.end) {
        arr[pos] = *(it + curr_range.start);
    } else {
        C left = build(LEFT_CHILD_IDX(pos), LEFT_SUB_RANGE(curr_range), it);
        C right = build(RIGHT_CHILD_IDX(pos, curr_range), RIGHT_SUB_RANGE(curr_range), it);
        arr[pos] = left + right;
    }

    return arr[pos];
}

template<class C>
template<class It>
segment_tree<C>::segment_tree(It begin, It end, size_t size) {
    size_t tree_size = (size * 2) - 1;
    arr.resize(tree_size);
    build(ROOT_IDX, MAX_RANGE(arr), begin);
}

template<class C>
C segment_tree<C>::operator[](size_t index) {
    int curr_idx = ROOT_IDX;
    size_t middle_pos;
    range curr_range = MAX_RANGE(arr);
    while(curr_range.start < curr_range.end) {
        middle_pos = MIDDLE_OF_RANGE(curr_range);
        if (index <= middle_pos) { // go left
            curr_idx = LEFT_CHILD_IDX(curr_idx);
            curr_range.end = middle_pos;
        } else { // go right
            curr_idx = RIGHT_CHILD_IDX(curr_idx, curr_range);
            curr_range.start = middle_pos + 1;
        }
    }

    return arr[curr_idx];
}

template<class C>
void segment_tree<C>::add(size_t index, C value) {
    range curr_range = MAX_RANGE(arr);
    if (index > curr_range.end) return;

    int curr_idx = ROOT_IDX;
    size_t middle_pos;
    while(curr_range.start < curr_range.end) {
        middle_pos = MIDDLE_OF_RANGE(curr_range);
        arr[curr_idx] += value;
        if (index <= middle_pos) { // go left
            curr_idx = LEFT_CHILD_IDX(curr_idx);
            curr_range.end = middle_pos;
        } else { // go right
            curr_idx = RIGHT_CHILD_IDX(curr_idx, curr_range);
            curr_range.start = middle_pos + 1;
        }
    }

    arr[curr_idx] += value; // add to the leaf as well
}

template<class C>
C segment_tree<C>::recursive_sum(size_t curr_node_idx, range query_range, range node_range) {
    // if it is a total overlap
    if (node_range.start >= query_range.start && node_range.end <= query_range.end)
        return arr[curr_node_idx];

    // this is a partial overlap case
    range node_left_sub_range = LEFT_SUB_RANGE(node_range);
    range node_right_sub_range = RIGHT_SUB_RANGE(node_range);
    size_t left_node_idx = LEFT_CHILD_IDX(curr_node_idx);
    size_t right_node_idx = RIGHT_CHILD_IDX(curr_node_idx, node_range);

    // if there is a no overlap case on the right. Just go on the left
    if (query_range.end <= node_left_sub_range.end)
        return recursive_sum(left_node_idx, query_range, node_left_sub_range);

    // there is a no overlap case on the left. Just go on the right
    if (query_range.start >= node_right_sub_range.start)
        return recursive_sum(right_node_idx, query_range, node_right_sub_range);

    // go both left and right
    C left = recursive_sum(left_node_idx, range(query_range.start, node_left_sub_range.end), node_left_sub_range);
    C right = recursive_sum(right_node_idx, range(node_right_sub_range.start, query_range.end), node_right_sub_range);
    return left + right;
}

template<class C>
C segment_tree<C>::sum(size_t from, size_t to) {
    return recursive_sum(ROOT_IDX, range(from, to), MAX_RANGE(arr));
}

template<class C>
C segment_tree<C>::sum(size_t idx) {
    return recursive_sum(ROOT_IDX, range(0, idx), MAX_RANGE(arr));
}