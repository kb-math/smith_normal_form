#ifndef SNF_H
#define SNF_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

namespace SmithNormalFormCalculator {

std::vector<int> add(std::vector<int> v, std::vector<int> w);

std::vector<int> scale(int a, std::vector<int> v);

int remainder(int a, int b);

int quotient(int a, int b);

std::vector<int> add(std::vector<int> v, std::vector<int> w);

std::vector<int> scale(int a, std::vector<int> v);

std::vector<std::vector<int>> transpose (std::vector<std::vector<int>> M);

void rowadd (std::vector<std::vector<int>> *M, int a, int i, int j, std::vector<std::vector<int>> *L = NULL);

void coladd (std::vector<std::vector<int>> *M, int a, int i, int j, std::vector<std::vector<int>> *R = NULL);

void rowswap (std::vector<std::vector<int>> *M, int i, int j, std::vector<std::vector<int>> *L = NULL);

void colswap (std::vector<std::vector<int>> *M, int i, int j, std::vector<std::vector<int>> *R = NULL);

void kill_row_entry (std::vector<std::vector<int>> *M, int col_ind, int row_kill, int row_aim, 
	std::vector<std::vector<int>> *A=NULL);

std::vector<std::vector<int>> identity_matrix(int d);

void kill_lower_part (std::vector<std::vector<int>> *M, int col_ind, int row_ind, 
	std::vector<std::vector<int>> *L=NULL);

void kill_col_entry (std::vector<std::vector<int>> *M, int row_ind, int col_left, int col_aim, 
	std::vector<std::vector<int>> *A=NULL);

void kill_right_part (std::vector<std::vector<int>> *M, int row_ind, int col_ind, 
	std::vector<std::vector<int>> *A=NULL);

void gcd_two_cols (std::vector<std::vector<int>> *M, int col_1, int col_2, int stage, 
	std::vector<std::vector<int>> *L=NULL, std::vector<std::vector<int>> *R=NULL);

void final_form (std::vector<std::vector<int>> *M, std::vector<std::vector<int>> *L=NULL, std::vector<std::vector<int>> *R=NULL);

}

#endif
