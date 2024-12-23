/**
 * Copyright (c) 2024 - Kleo
 * Authors:
 * - Antoine FRANKEL <antoine.frankel@epitech.eu>
 * NOTICE: All information contained herein is, and remains
 * the property of Kleo © and its suppliers, if any.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Kleo ©.
 */

#define ANTOINE

#include "limits.h"
#include "my_lib.hpp"

int main() {
    std::vector<int> l1, l2;
    std::vector<std::string> input = get_input();
    int max = 0;
    for (auto &line : input) {
        std::vector<std::string> tokens = split(line, "   ");
        l1.push_back(std::stoi(tokens[0]));
        l2.push_back(std::stoi(tokens[1]));
        max = std::max(max, l1.back());
        max = std::max(max, l2.back());
    }
    std::vector<int> sorted_l1 = sort(l1);
    std::vector<int> sorted_l2 = sort(l2);
    std::vector<int> arr(max);
    size_t sum = 0;
    for (size_t i = 0; i < sorted_l1.size(); i++) {
        sum += abs(sorted_l1[i] - sorted_l2[i]);
        arr[sorted_l2[i]]++;
    }
    std::cout << "First result: " << sum << std::endl;
	size_t sum_part2 = 0;
    for (size_t i = 0; i < sorted_l1.size(); i++) {
        int x = sorted_l1[i];
		sum_part2 += arr[x] * x;
    }

    std::cout << "Second result: " << sum_part2 << std::endl;
    return 0;
}
