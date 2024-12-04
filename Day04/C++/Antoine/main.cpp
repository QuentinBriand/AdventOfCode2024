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

#define WORD "XMAS"
#define WORD_LENGTH 4

int check_direction(std::vector<std::string> &grid, int ROWS, int COLS, int row, int col, int dir_row, int dir_col) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        int new_row = row + dir_row * i;
        int new_col = col + dir_col * i;

        if (new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS) {
            return 0;
        }

        if (grid[new_row][new_col] != WORD[i]) {
            return 0;
        }
    }
    return 1;
}

void find_xmas(std::vector<std::string> &grid, int ROWS, int COLS) {
    int count = 0;

    int directions[8][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1}};

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            for (int i = 0; i < 8; i++) {
                if (check_direction(grid, ROWS, COLS, row, col, directions[i][0], directions[i][1])) {
                    count++;
                }
            }
        }
    }

    printf("Total occurrences of 'XMAS': %d\n", count);
}

void my_find_x_mas(std::vector<std::string> &grid, int ROWS, int COLS) {
    int count = 0;
    int index = 1;
	int a_index = 0;
    for (int row = 1; row < ROWS - 1;) {
        a_index = grid[row].find('A', index);
        if (a_index == std::string::npos) {
            index = 1;
			a_index = 0;
			row++;
            continue;
        }
        char tl = grid[row - 1][a_index - 1];
        char tr = grid[row - 1][a_index + 1];
        char bl = grid[row + 1][a_index - 1];
        char br = grid[row + 1][a_index + 1];
        if (tl == 'M' && br == 'S' || tl == 'S' && br == 'M') {
            if (tr == 'M' && bl == 'S' || tr == 'S' && bl == 'M') {
                count++;
            }
        }
        index = a_index + 1;
    }
    printf("Total occurrences of 'X-MAS': %d\n", count);
}

int main(void) {
    auto input = get_input();
    int ROWS = input.size();
    int COLS = input[0].size();

    find_xmas(input, ROWS, COLS);
    my_find_x_mas(input, ROWS, COLS);
    return 0;
}
