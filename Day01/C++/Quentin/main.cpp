
#ifndef QUENTIN
    #define QUENTIN
    #define NAME "Quentin"
    #define COOKIE "53616c7465645f5fb0cb7b5bb9806356f97ca289cd994f856eeab93000a4133b3bf39c7e1d7988e87373986e95dca6170f978d0e297de240b4709295aee49d0a"
#endif

#include "limits.h"
#include "my_lib.hpp"

int main() {
    std::vector<std::string> input = get_input();

    std::vector<int> left;
    std::vector<int> right;
    std::unordered_map<int, int> counts;

    for(auto line : input) {
        int firstNbr = atoi(line.c_str());
        int nextIndex = 2;
        if (firstNbr != 1) {
            nextIndex += (int)std::ceil(std::log10(firstNbr));
        } else {
            nextIndex++;
        }
        int sndNbr = atoi(line.c_str() + nextIndex);
        left.push_back(firstNbr);
        right.push_back(sndNbr);

        counts[sndNbr]++;
    }

    left = sort(left);
    right = sort(right);

    auto len = left.size();
    size_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum += std::abs(left[i] - right[i]);
    }
    std::cout << "Sum: " << sum << std::endl;

    size_t similarity = 0;
    for (auto item : left) {
        similarity += item * counts[item];
    }

    std::cout << "Similarity: " << similarity << std::endl;
}