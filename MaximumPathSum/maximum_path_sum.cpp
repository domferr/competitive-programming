//
// Created by Domenico on 20/11/2021.
//

#include "maximum_path_sum.h"

#define LEFT_CHILD(index) arr[index].leftChild
#define RIGHT_CHILD(index) arr[index].rightChild
#define PARENT(index) arr[index].parent
#define VALUE(index) arr[index].val

tree::tree(std::initializer_list<node> list) {
    arr.reserve(list.size());
    int i = 0;
    for(node n: list) {
        arr.push_back(n);
        if (n.parent != NOELEM) {
            if (LEFT_CHILD(n.parent) == NOELEM)
                LEFT_CHILD(n.parent) = i;
            else if (RIGHT_CHILD(n.parent) == NOELEM)
                RIGHT_CHILD(n.parent) = i;
        }
        ++i;
    }
}

int tree::rec_maxpathsum(int index, int &maxSum) {
    if (index != NOELEM) {
        int maxLeft = rec_maxpathsum(LEFT_CHILD(index), maxSum);
        int maxRight = rec_maxpathsum(RIGHT_CHILD(index), maxSum);

        if (maxLeft + maxRight + VALUE(index) > maxSum)
            maxSum = maxLeft + maxRight + VALUE(index);

        return std::max(maxLeft, maxRight) + VALUE(index);
    }

    return 0;
}

int tree::maxpathsum() {
    int maxSum = 0;
    rec_maxpathsum(0, maxSum);
    return maxSum;
}
