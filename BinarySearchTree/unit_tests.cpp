//
// Created by Domenico on 03/11/2021.
//

#include <gtest/gtest.h>
#include "bst.h"

TEST(BSTTestInsert, BasicAssertions) {
    bst<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(3);
    tree.insert(12);
    tree.insert(1);
    tree.insert(32);
    tree.insert(3);
    EXPECT_EQ(2, 2);
}

TEST(BSTTestConstructorBraces, BasicAssertions) {
    bst<int> tree {10, 45, 34, 2, 8};
    EXPECT_EQ(2, 2);
}

TEST(BSTTestInorderIteratorEmpty, BasicAssertions) {
    bst<int> tree{};
    bst<int>::iterator it = tree.begin();
    bst<int>::iterator end = tree.end();
    int i = 0;
    while (it != end) {
        i++;
        ++it;
    }
    EXPECT_EQ(i, 0);

    i = 0;
    for (int val:tree) {
        i++;
    }
    EXPECT_EQ(i, 0);
}

TEST(BSTTestInorderIteratorOneElement, BasicAssertions) {
    bst<int> tree{};
    tree.insert(18);

    bst<int>::iterator it = tree.begin();
    bst<int>::iterator end = tree.end();
    int i = 0;
    while(it != end) {
        int elem = *it;
        EXPECT_EQ(elem, 18);
        EXPECT_EQ(i, 0);
        i++;
        ++it;
    }

    i = 0;
    for (int val:tree) {
        EXPECT_EQ(val, 18);
        EXPECT_EQ(i, 0);
        i++;
    }
}

void test_inorder_iterator(bst<int> &tree, const std::vector<int>& sorted) {
    bst<int>::iterator it = tree.begin();
    bst<int>::iterator end = tree.end();
    int i = 0;
    while(it != end) {
        int elem = *it;
        EXPECT_EQ(elem, sorted[i]);
        i++;
        ++it;
    }

    i = 0;
    for (int val:tree) {
        EXPECT_EQ(val, sorted[i]);
        i++;
    }
}

TEST(BSTTestInorderIteratorLeftOnlySubtree, BasicAssertions) {
    bst<int> tree{};
    std::vector<int> sorted = { 2, 9, 18 };
    tree.insert(sorted[2]);
    tree.insert(sorted[1]);
    tree.insert(sorted[0]);

    test_inorder_iterator(tree, sorted);
}

TEST(BSTTestInorderIteratorRightOnlySubtree, BasicAssertions) {
    bst<int> tree{};
    std::vector<int> sorted = { 2, 9, 18, 24 };
    tree.insert(sorted[0]);
    tree.insert(sorted[1]);
    tree.insert(sorted[2]);
    tree.insert(sorted[3]);

    test_inorder_iterator(tree, sorted);
}

TEST(BSTTestInorderIterator, BasicAssertions) {
    bst<int> tree{};
    std::vector<int> sorted = { 2, 9, 18, 24, 56, 78, 92 };
    tree.insert(sorted[3]);
    tree.insert(sorted[1]);
    tree.insert(sorted[4]);
    tree.insert(sorted[0]);
    tree.insert(sorted[6]);
    tree.insert(sorted[2]);
    tree.insert(sorted[5]);

    test_inorder_iterator(tree, sorted);
}

TEST(BSTTestMinZeroElements, BasicAssertions) {
    bst<int> tree;
    EXPECT_ANY_THROW(tree.min());
}

TEST(BSTTestMinOneElement, BasicAssertions) {
    bst<int> tree;
    tree.insert(10);
    int minimum = tree.min();
    EXPECT_EQ(minimum, 10);
}

TEST(BSTTestMinMultipleElements, BasicAssertions) {
    bst<int> tree {10, 23, 2, 4, 17, 9, 17};
    int minimum = tree.min();
    EXPECT_EQ(minimum, 2);
}

TEST(BSTTestMaxZeroElements, BasicAssertions) {
    bst<int> tree;
    EXPECT_ANY_THROW(tree.max());
}

TEST(BSTTestMaxMultipleElements, BasicAssertions) {
    bst<int> tree {10, 1, 43, 3};
    int maximum = tree.max();
    EXPECT_EQ(maximum, 43);
}

TEST(BSTTestContainsEmptyTree, BasicAssertions) {
    bst<int> tree;
    EXPECT_EQ(false, tree.contains(10));
}

TEST(BSTTestContainsOneElement, BasicAssertions) {
    bst<int> tree;
    tree.insert(10);
    EXPECT_EQ(true, tree.contains(10));
}

TEST(BSTTestNotContainsOneElement, BasicAssertions) {
    bst<int> tree;
    tree.insert(2);
    EXPECT_EQ(false, tree.contains(10));
}

TEST(BSTTestContainsMultipleElements, BasicAssertions) {
    bst<int> tree {2, 3, 1, 9};
    EXPECT_EQ(false, tree.contains(10));
    EXPECT_EQ(true, tree.contains(2));
    EXPECT_EQ(false, tree.contains(22));
    EXPECT_EQ(true, tree.contains(9));
    EXPECT_EQ(true, tree.contains(3));
    EXPECT_EQ(true, tree.contains(1));
}