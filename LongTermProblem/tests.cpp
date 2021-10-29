//
// Created by Domenico on 29/10/2021.
//

#include <gtest/gtest.h>
#include "longtermproblem.h"

TEST(LongTermProblemTest1, BasicAssertions) {
    std::vector<std::string> strings {"another useful string", "happiness", "hello", "i'm so happy", "my friends", "sometimes"};
    std::string key = "my friends";
    size_t res = long_term_problem(strings, key);
    EXPECT_EQ(res, 4);
}

TEST(LongTermProblemTest2, BasicAssertions) {
    std::vector<std::string> strings {"another useful string", "happiness", "hello", "i'm so happy", "my friends"};
    std::string key = "hello";
    size_t res = long_term_problem(strings, key);
    EXPECT_EQ(res, 2);
}

TEST(LongTermProblemTest3, BasicAssertions) {
    std::vector<std::string> strings {"another useful string", "happiness", "hello", "i'm so happy", "my friends", "sometimes"};
    std::string key = "happiness";
    size_t res = long_term_problem(strings, key);
    EXPECT_EQ(res, 1);
}

TEST(LongTermProblemTest4, BasicAssertions) {
    std::vector<std::string> strings {"another useful string", "happiness", "hello", "i'm so happy", "my friends", "sometimes"};
    std::string key = "this string is not in the vector of strings";
    size_t res = long_term_problem(strings, key);
    EXPECT_EQ(res, -1);
}

TEST(LongTermProblemTest5, BasicAssertions) {
    std::vector<std::string> strings {"nothing", "happiness", "hello", "i'm so happy", "my friends", "sometimes"};
    std::string key = "another useful string";
    size_t res = long_term_problem(strings, key);
    EXPECT_EQ(res, -1);
}

TEST(LongTermProblemTest6, BasicAssertions) {
    std::vector<std::string> strings {"another useful string", "happiness", "hello", "i'm so happy", "my friends", "sometimes"};
    std::string key = "my FRIENDS";
    size_t res = long_term_problem(strings, key);
    EXPECT_EQ(res, -1);
}