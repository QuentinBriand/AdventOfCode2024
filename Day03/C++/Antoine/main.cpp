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
#include "my_lib.hpp"
#include "regex"

int main(void) {
    auto input = get_input();
    size_t part1 = 0, part2 = 0;
    bool mul_enabled = true;

    std::regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::regex doPattern(R"(do())");
    std::regex dontPattern(R"(don't())");

    for (auto &line : input) {
        auto current = line.begin();
        while (current != line.end()) {
            std::smatch match;
            std::string current_str = std::string(current, line.end());
            int do_index = current_str.find("do()");
            int dont_index = current_str.find("don't()");

            if (std::regex_search(current_str, match, mulPattern)) {
                size_t position = match.position(0);
				if (mul_enabled && dont_index != std::string::npos && position > dont_index) {
					mul_enabled = false;
				} else if (!mul_enabled && do_index != std::string::npos && position > do_index) {
					mul_enabled = true;
				}

                if (mul_enabled) {
                    part2 += std::stoi(match[1]) * std::stoi(match[2]);
                }
                part1 += std::stoi(match[1]) * std::stoi(match[2]);
                current += match.position() + match.length();
            } else {
                ++current;
            }
        }
    }

    std::cout << "Part 1: " << part1 << std::endl;
    std::cout << "Part 2: " << part2 << std::endl;
    return 0;
}
