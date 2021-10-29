//
// Created by Domenico on 29/10/2021.
//

#include <gtest/gtest.h>
#include "longtermproblem.h"

TEST(LongTermProblemTest1, BasicAssertions) {
    std::vector<std::string> strings {"Hello", "my friends", "I'm so happy", "another useful string", "sometimes", "happiness"};
    std::string key = "my friends";
    auto res = long_term_problem(strings, key);
    EXPECT_EQ(res, 1);
}

TEST(LongTermProblemTest2, BasicAssertions) {
    std::vector<std::string> strings {"Hello", "my friends", "I'm so happy", "another useful string", "sometimes", "happiness"};
    std::string key = "Hello";
    auto res = long_term_problem(strings, key);
    EXPECT_EQ(res, 0);
}

TEST(LongTermProblemTest3, BasicAssertions) {
    std::vector<std::string> strings {"Hello", "my friends", "I'm so happy", "another useful string", "sometimes", "happiness"};
    std::string key = "happiness";
    auto res = long_term_problem(strings, key);
    EXPECT_EQ(res, 5);
}

TEST(LongTermProblemTest4, BasicAssertions) {
    std::vector<std::string> strings {"Hello", "my friends", "I'm so happy", "another useful string", "sometimes", "happiness"};
    std::string key = "this string is not in the vector of strings";
    auto res = long_term_problem(strings, key);
    EXPECT_EQ(res, -1);
}

TEST(LongTermProblemTest5, BasicAssertions) {
    std::vector<std::string> strings {"Hello", "my friends", "I'm so happy", "another useful string", "sometimes", "happiness"};
    std::string key = "another useful string";
    auto res = long_term_problem(strings, key);
    EXPECT_EQ(res, 3);
}

TEST(LongTermProblemTest6, BasicAssertions) {
    std::vector<std::string> strings {"Hello", "my friends", "I'm so happy", "another useful string", "sometimes", "happiness"};
    std::string key = "my FRIENDS";
    auto res = long_term_problem(strings, key);
    EXPECT_EQ(res, -1);
}