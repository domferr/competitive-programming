//
// Created by Domenico on 20/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_MAXIMUM_PATH_SUM_H
#define COMPETITIVE_PROGRAMMING_MAXIMUM_PATH_SUM_H

#include <vector>
#include <iostream>

#define NOELEM -1

struct tree {
    struct node {
        explicit node(int v, int par = NOELEM) : val(v), parent(par), leftChild(NOELEM), rightChild(NOELEM) {}
        int val;
        int parent;
        int leftChild;
        int rightChild;
    };

    tree(std::initializer_list<node> list);
    int maxpathsum();

private:
    int rec_maxpathsum(int index, int &maxSum);
    std::vector<node> arr;
};

#endif //COMPETITIVE_PROGRAMMING_MAXIMUM_PATH_SUM_H
