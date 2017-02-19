#ifndef SNF_H
#define SNF_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int digit_len (int a);

int entry_fatness(vector<vector<int>> M);

void print_matrix (vector<vector<int>> M);

void print_aug_matrix (vector<vector<int>> M, vector<vector<int>> A);

int my_max(vector<int> v);

vector<int> add(vector<int> v, vector<int> w);

vector<int> scale(int a, vector<int> v);

int remainder(int a, int b);

int quotient(int a, int b);

vector<int> add(vector<int> v, vector<int> w);

vector<int> scale(int a, vector<int> v);

vector<vector<int>> transpose (vector<vector<int>> M);

void rowadd (vector<vector<int>> *M, int a, int i, int j, vector<vector<int>> *L = NULL);

void coladd (vector<vector<int>> *M, int a, int i, int j, vector<vector<int>> *R = NULL);

void rowswap (vector<vector<int>> *M, int i, int j, vector<vector<int>> *L = NULL);

void colswap (vector<vector<int>> *M, int i, int j, vector<vector<int>> *R = NULL);

void kill_row_entry (vector<vector<int>> *M, int col_ind, int row_kill, int row_aim, vector<vector<int>> *A=NULL);

vector<vector<int>> identity_matrix(int d);

void kill_lower_part (vector<vector<int>> *M, int col_ind, int row_ind, vector<vector<int>> *L=NULL);

void kill_col_entry (vector<vector<int>> *M, int row_ind, int col_left, int col_aim, vector<vector<int>> *A=NULL);

void kill_right_part (vector<vector<int>> *M, int row_ind, int col_ind, vector<vector<int>> *A=NULL);

void gcd_two_cols (vector<vector<int>> *M, int col_1, int col_2, int stage, vector<vector<int>> *L=NULL, vector<vector<int>> *R=NULL);

void final_form (vector<vector<int>> *M, vector<vector<int>> *L=NULL, vector<vector<int>> *R=NULL);


#endif
