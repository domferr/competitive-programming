//
// Created by Domenico on 12/11/2021.
//

#include "segment_tree.h"

#define LEFT_CHILD_IDX(idx) ((2 * (idx)) + 1)
#define RIGHT_CHILD_IDX(idx) ((2 * (idx)) + 2)
#define PARENT_IDX(idx) (((idx) - 1) / 2)
#define ROOT_IDX 0

template<class C>
C segment_tree<C>::rec_constr(size_t curr_idx, size_t segment_start, size_t segment_end, size_t max_seg_end) {
    size_t segment_middle = segment_start + (segment_end - segment_start) / 2;
    size_t left_node_idx = LEFT_CHILD_IDX(curr_idx);
    size_t right_node_idx = RIGHT_CHILD_IDX(curr_idx);

    if (left_node_idx < heap.size() && right_node_idx < heap.size()) {
        if (segment_middle + 1 > max_seg_end) { // prune right subtree. just go left
            heap[curr_idx] = rec_constr(left_node_idx, segment_start, segment_middle, max_seg_end);
        } else {
            C left = rec_constr(left_node_idx, segment_start, segment_middle, max_seg_end);
            C right = rec_constr(right_node_idx, segment_middle + 1, segment_end, max_seg_end);
            heap[curr_idx] = left + right;
        }
    }

    return heap[curr_idx];
}

template<class C>
template<class It>
segment_tree<C>::segment_tree(It begin, It end, size_t size) {
    int tree_height = ceil(log2(size));
    auto max_len = (size_t) pow(2, tree_height);
    size_t heap_size = (max_len * 2) - 1;
    heap.resize(heap_size);
    max_segment_end = max_len - 1;
    size_t pos = heap_size - max_len;

    // insert the given elements as leaves
    while (begin != end) {
        heap[pos] = *begin;
        begin++;
        pos++;
    }

    // setup the rest of the tree
    rec_constr(ROOT_IDX, 0, max_segment_end, size - 1);
}

template<class C>
C segment_tree<C>::operator[](size_t idx) {
    //return heap[heap.size() - max_segment_end + idx - 1];
    return heap[max_segment_end + idx];
}

template<class C>
void segment_tree<C>::add(size_t index, C value) {
    size_t segment_start = 0;
    size_t segment_end = max_segment_end;
    size_t middle_pos;
    int curr_idx = ROOT_IDX;
    while (curr_idx < heap.size()) {
        middle_pos = segment_start + (segment_end - segment_start) / 2;
        heap[curr_idx] += value;
        if (index <= middle_pos) { // go left
            curr_idx = LEFT_CHILD_IDX(curr_idx);
            segment_end = middle_pos;
        } else { // go right
            curr_idx = RIGHT_CHILD_IDX(curr_idx);
            segment_start = middle_pos + 1;
        }
    }
}

template<class C>
C segment_tree<C>::recursive_sum(size_t curr_node_idx, size_t query_start, size_t query_end, size_t node_start, size_t node_end) {
    // if it is a total overlap
    if (node_start >= query_start && node_end <= query_end)
        return heap[curr_node_idx];

    // this is a partial overlap case
    size_t node_middle = node_start + (node_end - node_start) / 2;
    size_t left_node_idx = LEFT_CHILD_IDX(curr_node_idx);
    size_t right_node_idx = RIGHT_CHILD_IDX(curr_node_idx);

    // if there is a no overlap case on the right. Just go on the left
    if (query_end <= node_middle)
        return recursive_sum(left_node_idx, query_start, query_end, node_start, node_middle);

    // there is a no overlap case on the left. Just go on the right
    if (query_start >= node_middle + 1)
        return recursive_sum(right_node_idx, query_start, query_end, node_middle + 1, node_end);

    // go both left and right
    C left = recursive_sum(left_node_idx, query_start, node_middle, node_start, node_middle);
    C right = recursive_sum(right_node_idx, node_middle + 1, query_end, node_middle + 1, node_end);
    return left + right;
}

template<class C>
C segment_tree<C>::sum(size_t from, size_t to) {
    return recursive_sum(ROOT_IDX, from, to, 0, max_segment_end);
}

template<class C>
C segment_tree<C>::sum(size_t idx) {
    return recursive_sum(ROOT_IDX, 0, idx, 0, max_segment_end);
}