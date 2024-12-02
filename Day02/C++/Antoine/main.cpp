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

bool is_report_safe(std::vector<int> report) {
    bool increasing = false;
    if (report[0] < report[1]) {
        increasing = true;
    }
    for (size_t i = 1; i < report.size(); i++) {
        auto diff = abs(report[i - 1] - report[i]);

        if (diff < 1 || diff > 3) {
            return false;
        }
        if (increasing && report[i - 1] > report[i]) {
            return false;
        } else if (!increasing && report[i - 1] < report[i]) {
            return false;
        }
    }
    return true;
}

bool can_report_be_safe(std::vector<int> report) {
	for (size_t i = 0; i < report.size(); i++) {
		auto copy = report;
		copy.erase(copy.begin() + i);
		if (is_report_safe(copy)) {
			return true;
		}
	}
	return false;
}

int main(void) {
    auto input = get_input();
    int part1 = 0, part2 = 0;
    for (const auto &report : input) {
		auto splitted_report = split<int>(report, " ");
        if (is_report_safe(splitted_report)) {
			part1++;
        }
		if (can_report_be_safe(splitted_report)) {
			part2++;
		}
    }

    std::cout << "First star: " << part1 << std::endl;
	std::cout << "Second star: " << part2 << std::endl;

    return 0;
}
