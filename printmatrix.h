#ifndef PRINT_MATRIX_H
#define PRINT_MATRIX_H

#include <vector>

int digit_len (int a);

int entry_fatness(std::vector<std::vector<int>> M);

void print_matrix (std::vector<std::vector<int>> M);

void print_aug_matrix (std::vector<std::vector<int>> M, std::vector<std::vector<int>> A);

#endif
