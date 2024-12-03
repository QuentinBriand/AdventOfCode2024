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

#ifndef MY_LIB_HPP
#define MY_LIB_HPP

#include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define RESOURCES_PATH "./resources/"

#ifdef ANTOINE
#define NAME "Antoine"
#define COOKIE "53616c7465645f5f9ebf055dfdb60c82e03c13a4577d7c31f316a73950a740b4846c37845ea6cfa74fa8714910dad48b29bec156a93fc6bdfe937cf1c3bb5479"
#endif

std::vector<std::string> read_file(const std::string &filename) {
    std::vector<std::string> lines;
    std::string line;

    std::ifstream file(filename);
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::string> get_input() {
#ifndef COOKIE
#define COOKIE ""
#define NAME ""
    std::cerr << "Please provide your session cookie in the COOKIE variable and your name in the NAME variable." << std::endl;
    exit(84);
#endif
    int today = std::time(nullptr) / 86400 % 31;

    std::ostringstream foldername;
    foldername << "Day" << std::setw(2) << std::setfill('0') << today;
    std::string filename = RESOURCES_PATH + foldername.str() + "/" + NAME + ".txt";
    if (std::filesystem::exists(filename)) {
		std::cout << "Reading from file " << filename << std::endl;
        return read_file(filename);
    }

	std::filesystem::create_directories(RESOURCES_PATH + foldername.str());

    std::string url = "https://adventofcode.com/2024/day/" + std::to_string(today) + "/input";
    std::string command = "curl -s " + url + " -H \"Cookie: session=" + COOKIE + "\"";
    std::vector<std::string> result;
    char buffer[65536];
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
            result.push_back(buffer);
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);

    if (result[0] == "Puzzle inputs differ by user.  Please log in to get your puzzle input.\n") {
        std::cerr << "Please provide your session cookie in the COOKIE variable." << std::endl;
        exit(84);
    }

    std::ofstream file(filename);
    for (auto &line : result) {
        file << line;
    }
    file.close();
    return result;
}

template <typename T>
std::vector<T> split(std::string s, const std::string &delimiter) {
	std::vector<T> tokens;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		tokens.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	tokens.push_back(s);

	return tokens;
}

template <>
std::vector<std::string> split(std::string s, const std::string &delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

template <>
std::vector<int> split(std::string s, const std::string &delimiter) {
    std::vector<int> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(std::atoi(token.c_str()));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(std::atoi(s.c_str()));

    return tokens;
}

template <typename T>
std::vector<T> sort(const std::vector<T> &v) {
    std::vector<T> sorted = v;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

#endif  // MY_LIB_HPP
