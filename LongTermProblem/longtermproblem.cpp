//
// Created by Domenico on 29/10/2021.
//

#include "longtermproblem.h"

size_t binary_search(const std::vector<std::string> &strings, size_t start, size_t end, const std::string& key);

size_t long_term_problem(const std::vector<std::string> &strings, const std::string& key) {
    return binary_search(strings, 0, strings.size(), key);
}

size_t binary_search(const std::vector<std::string> &strings, size_t start, size_t end, const std::string& key) {
    if (start >= end) return -1;

    size_t middle_position = start + ((end - start) / 2);
    int comparison = key.compare(strings[middle_position]);
    if (comparison == 0) return middle_position;

    if (comparison < 0) {
        return binary_search(strings, start, middle_position, key);
    }

    return binary_search(strings, middle_position+1, end, key);
}