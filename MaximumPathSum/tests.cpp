//
// Created by Domenico on 20/11/2021.
//

#include <gtest/gtest.h>
#include "maximum_path_sum.h"

TEST(MaximumPathSum1, BasicAssertions) {
    tree tr {
        tree::node(3),
        tree::node(4, 0),
        tree::node(5, 0),
        tree::node(-10, 1),
        tree::node(4, 1),
    };

    int solution = 16;
    int res = tr.maxpathsum();
    EXPECT_EQ(res, solution);
}

TEST(MaximumPathSum2, BasicAssertions) {
    tree tr {
        tree::node(-15),
        tree::node(5, 0),
        tree::node(6, 0),
        tree::node(-8, 1),
        tree::node(1, 1),
        tree::node(2, 3),
        tree::node(-3, 3),
        tree::node(3, 2),
        tree::node(9, 2),
        tree::node(0, 8),
        tree::node(4, 9),
        tree::node(-1, 9),
        tree::node(10, 11),
    };

    int solution = 27;
    int res = tr.maxpathsum();
    EXPECT_EQ(res, solution);
}