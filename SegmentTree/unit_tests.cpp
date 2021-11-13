//
// Created by Domenico on 12/11/2021.
//

#include <gtest/gtest.h>
#include "segment_tree.h"

TEST(SegmentTreeTestInitializerList, BasicAssertions) {
    segment_tree<int> st { 3, 1, -2, 4, 6, 13, 2, 0 };

    // test with a missing right leaf
    segment_tree<int> st2 { 3, 1, -2, 4, 6, 13, 2 };

    // test with missing elements in the right subtree
    segment_tree<int> without_a_subtree { 3, 1, -2, 4, 6, 13 };

    // test with just one element in the right subtree
    segment_tree<int> one_elem_subtree { 3, 1, -2, 4, 6 };

    EXPECT_EQ(8, 8);
}

TEST(SegmentTreeTestConstructVector, BasicAssertions) {
    std::vector<int> vec { 3, 1, -2, 4, 6, 13, 2, 0 };
    segment_tree<int> st { vec };

    // test with a missing right leaf
    std::vector<int> vec_missing_right { 3, 1, -2, 4, 6, 13, 2 };
    segment_tree<int> with_missing_right { vec_missing_right };

    // test with missing elements in the right subtree
    std::vector<int> vec_without_a_subtree { 3, 1, -2, 4, 6, 13 };
    segment_tree<int> without_a_subtree { vec_without_a_subtree };

    // test with just one element in the right subtree
    std::vector<int> vec_one_elem_subtree { 3, 1, -2, 4, 6 };
    segment_tree<int> one_elem_subtree { vec_one_elem_subtree };
}

template<class C>
void test_access(const std::vector<C> &vec) {
    segment_tree<int> st { vec };
    for (int i = 0; i < vec.size(); i++) {
        EXPECT_EQ(st[i], vec[i]);
    }
}

TEST(SegmentTreeTestAccessOperator, BasicAssertions) {
    std::vector<int> vec { 3, 1, -2, 4, 6, 13, 2, 0 };
    test_access(vec);

    // test with a missing right leaf
    std::vector<int> vec_missing_right { 3, 1, -2, 4, 6, 13, 2 };
    test_access(vec_missing_right);

    // test with missing elements in the right subtree
    std::vector<int> vec_without_a_subtree { 3, 1, -2, 4, 6, 13 };
    test_access(vec_without_a_subtree);

    // test with just one element in the right subtree
    std::vector<int> vec_one_elem_subtree { 3, 1, -2, 4, 6 };
    test_access(vec_one_elem_subtree);
}

template<class C>
void test_add(const std::vector<C> &vec, const C &val) {
    segment_tree<C> st { vec };
    for(size_t pos = 0; pos < vec.size(); pos++) {
        st.add(pos, val);
        EXPECT_EQ(st[pos], vec[pos] + val);
    }
}

TEST(SegmentTreeTestAdd, BasicAssertions) {
    std::vector<int> vec { 3, 1, -2, 4, 6, 13, 2, 0 };
    test_add(vec, 10);

    // test with a missing right leaf
    std::vector<int> vec_missing_right { 3, 1, -2, 4, 6, 13, 2 };
    test_add(vec_missing_right, 10);

    // test with missing elements in the right subtree
    std::vector<int> vec_without_a_subtree { 3, 1, -2, 4, 6, 13 };
    test_add(vec_without_a_subtree, 10);

    // test with just one element in the right subtree
    std::vector<int> vec_one_elem_subtree { 3, 1, -2, 4, 6 };
    test_add(vec_one_elem_subtree, 10);
}

template<class C>
void test_sum(const std::vector<C> &vec) {
    segment_tree<C> st { vec };
    // compute the sums
    std::vector<C> sums(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        sums[i] = vec[i];
        if (i > 0) sums[i] += sums[i-1];
    }
    for (int i = 0; i < sums.size(); ++i) {
        //std::cout << i << " ";
        EXPECT_EQ(st.sum(i), sums[i]);
    }
}

TEST(SegmentTreeTestSum, BasicAssertions) {
    std::vector<int> vec { 3, 1, -2, 4, 6, 13, 2, 0 };
    test_sum(vec);

    // test with a missing right leaf
    std::vector<int> vec_missing_right { 3, 1, -2, 4, 6, 13, 2 };
    test_sum(vec_missing_right);

    // test with missing elements in the right subtree
    std::vector<int> vec_without_a_subtree { 3, 1, -2, 4, 6, 13 };
    test_sum(vec_without_a_subtree);

    // test with just one element in the right subtree
    std::vector<int> vec_one_elem_subtree { 3, 1, -2, 4, 6 };
    test_sum(vec_one_elem_subtree);
}

template<class C>
void test_range_sum(const std::vector<C> &vec) {
    segment_tree<C> st { vec };
    // compute the sums
    std::vector<C> sums(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        sums[i] = vec[i];
        if (i > 0) sums[i] += sums[i-1];
    }
    for (int i = 0; i < sums.size(); ++i) {
        for (int j = i; j < sums.size(); ++j) {
            int left_sum = i == 0 ? 0:sums[i-1];
            EXPECT_EQ(st.sum(i, j), sums[j] - left_sum);
        }
    }
}

TEST(SegmentTreeTestRangeSum, BasicAssertions) {
    std::vector<int> vec { 3, 1, -2, 4, 6, 13, 2, 0 };
    test_range_sum(vec);

    // test with a missing right leaf
    std::vector<int> with_missing_right { 3, 1, -2, 4, 6, 13, 2 };
    test_range_sum(with_missing_right);

    // test with missing elements in the right subtree
    std::vector<int> vec_without_a_subtree { 3, 1, -2, 4, 6, 13 };
    test_range_sum(vec_without_a_subtree);

    // test with just one element in the right subtree
    std::vector<int> vec_one_elem_subtree { 3, 1, -2, 4, 6 };
    test_range_sum(vec_one_elem_subtree);
}