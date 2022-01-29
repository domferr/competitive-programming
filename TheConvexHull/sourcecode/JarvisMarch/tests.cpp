//
// Created by Domenico on 25/01/2022.
//

#include <gtest/gtest.h>
#include "jarvismarch.h"
#include "../testsuite/testsuite.h"

TEST(JarvisMarchTest1, BasicAssertions) {
    std::vector<Point> points = get_test_set_1();
    std::vector<Point> res = jarvismarch(points);
    EXPECT_EQ(res, get_solution_set_1());
}

TEST(JarvisMarchTest2, BasicAssertions) {
    std::vector<Point> points = get_test_set_2();
    std::vector<Point> res = jarvismarch(points);
    EXPECT_EQ(res, get_solution_set_2());
}