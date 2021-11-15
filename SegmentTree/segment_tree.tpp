//
// Created by Domenico on 12/11/2021.
//

#include "segment_tree.h"

// nodes indexes in the array
#define LEFT_CHILD_IDX(idx) ((2 * (idx)) + 1)
#define RIGHT_CHILD_IDX(idx) ((2 * (idx)) + 2)
#define PARENT_IDX(idx) (((idx) - 1) / 2)
#define ROOT_IDX 0

// ranges
#define MIDDLE_OF_RANGE(ran) ((ran).start + (((ran).end - (ran).start) / 2))
#define LEFT_SUB_RANGE(ran) range( (ran).start, MIDDLE_OF_RANGE(ran) )
#define RIGHT_SUB_RANGE(ran) range( MIDDLE_OF_RANGE(ran) + 1, (ran).end )

template<class C>
C segment_tree<C>::build(size_t curr_idx, range curr_range, size_t max_seg_end) {
    size_t left_node_idx = LEFT_CHILD_IDX(curr_idx);
    size_t right_node_idx = RIGHT_CHILD_IDX(curr_idx);
    range left_sub_range = LEFT_SUB_RANGE(curr_range);
    range right_sub_range = RIGHT_SUB_RANGE(curr_range);

    //std::cout << "( " << curr_range.start << ", " << curr_range.end << " )" << std::endl;
    if (left_node_idx < arr.size() && right_node_idx < arr.size()) {
        if (right_sub_range.start > max_seg_end) { // prune right subtree. just go left
            arr[curr_idx] = build(left_node_idx, left_sub_range, max_seg_end);
            //std::cout << "l  ( " << curr_range.start << ", " << curr_range.end << " ) = " << arr[curr_idx] << std::endl;
        } else {
            C left = build(left_node_idx, left_sub_range, max_seg_end);
            C right = build(right_node_idx, right_sub_range, max_seg_end);
            arr[curr_idx] = left + right;
            //std::cout << "lr ( " << curr_range.start << ", " << curr_range.end << " ) = " << arr[curr_idx] << std::endl;
        }
    }

    return arr[curr_idx];
}

template<class C>
template<class It>
segment_tree<C>::segment_tree(It begin, It end, size_t size) {
    int tree_height = ceil(log2(size));
    auto max_len = (size_t) pow(2, tree_height);
    size_t heap_size = (max_len * 2) - 1;
    arr.resize(heap_size);
    max_segment_end = max_len - 1;
    size_t pos = heap_size - max_len;

    // insert the given elements as leaves
    while (begin != end) {
        arr[pos] = *begin;
        begin++;
        pos++;
    }

    // build the rest of the tree
    build(ROOT_IDX, range(0, max_segment_end), size - 1);
}

template<class C>
C segment_tree<C>::operator[](size_t idx) {
    return arr[max_segment_end + idx];
}

template<class C>
void segment_tree<C>::add(size_t index, C value) {
    range curr_range = range(0, max_segment_end);
    size_t middle_pos;
    int curr_idx = ROOT_IDX;
    while (curr_idx < arr.size()) {
        middle_pos = MIDDLE_OF_RANGE(curr_range);
        arr[curr_idx] += value;
        if (index <= middle_pos) { // go left
            curr_idx = LEFT_CHILD_IDX(curr_idx);
            curr_range.end = middle_pos;
        } else { // go right
            curr_idx = RIGHT_CHILD_IDX(curr_idx);
            curr_range.start = middle_pos + 1;
        }
    }
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
    size_t right_node_idx = RIGHT_CHILD_IDX(curr_node_idx);

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
    return recursive_sum(ROOT_IDX, range(from, to), range(0, max_segment_end));
}

template<class C>
C segment_tree<C>::sum(size_t idx) {
    return recursive_sum(ROOT_IDX, range(0, idx), range(0, max_segment_end));
}