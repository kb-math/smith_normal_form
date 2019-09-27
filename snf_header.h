#ifndef SNF_H
#define SNF_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "matrix/matrix.hpp"

namespace SmithNormalFormCalculator {
int remainder(int a, int b);

int quotient(int a, int b);

//TODO: these should be operators in a vector/matrix class
std::vector<int> add(std::vector<int> v, std::vector<int> w);
std::vector<int> scale(int a, std::vector<int> v);

void rowAdd (Matrix<int>& M, int a, int i, int j, 
	Matrix<int> *L = NULL);

void columnAdd (Matrix<int>& M, int a, int i, int j, 
	Matrix<int> *R = NULL);

void rowSwap (Matrix<int>& M, int i, int j, 
	Matrix<int> *L = NULL);

void columnSwap (Matrix<int>& M, int i, int j, 
	Matrix<int> *R = NULL);

void killRowEntry (Matrix<int>& M, int columnIndex, int killerRowIndex, 
	int victimRowIndex, Matrix<int> *A=NULL);

Matrix<int> identity_matrix(int d);

void killLowerPart (Matrix<int>& M, int columnIndex, int rowIndex, 
	Matrix<int> *L=NULL);

void killColumnEntry (Matrix<int>& M, int rowIndex, int killerColumnIndex, 
	int victimColumnIndex, Matrix<int> *A=NULL);

void killRightPart (Matrix<int>& M, int rowIndex, int columnIndex, 
	Matrix<int> *A=NULL);

void CreateGCDinTopLeft (Matrix<int>& M, int leftColumnIndex, int rightColumnIndex,
	int stage, Matrix<int> *L=NULL, Matrix<int> *R=NULL);

void ComputeSmithNormalForm (Matrix<int>& M, Matrix<int> *L=NULL, 
	Matrix<int> *R=NULL);

}

#endif
