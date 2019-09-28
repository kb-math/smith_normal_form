#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "matrix.hpp"


//TODO: these should be operators in a vector/matrix class
std::vector<int> add(std::vector<int> v, std::vector<int> w);
std::vector<int> scale(int a, std::vector<int> v);

Matrix<int> identity_matrix(int d);

void rowAdd (Matrix<int>& M, int a, int i, int j, 
	Matrix<int> *L = NULL);

void columnAdd (Matrix<int>& M, int a, int i, int j, 
	Matrix<int> *R = NULL);

void rowSwap (Matrix<int>& M, int i, int j, 
	Matrix<int> *L = NULL);

void columnSwap (Matrix<int>& M, int i, int j, 
	Matrix<int> *R = NULL);


#endif
