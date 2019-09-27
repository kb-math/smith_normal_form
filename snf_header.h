#ifndef SNF_H
#define SNF_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

namespace SmithNormalFormCalculator {
int remainder(int a, int b);

int quotient(int a, int b);

//TODO: these should be operators in a vector/matrix class
std::vector<int> add(std::vector<int> v, std::vector<int> w);
std::vector<int> scale(int a, std::vector<int> v);

std::vector<std::vector<int>> transpose (std::vector<std::vector<int>> M);

void rowAdd (std::vector<std::vector<int>>& M, int a, int i, int j, 
	std::vector<std::vector<int>> *L = NULL);

void columnAdd (std::vector<std::vector<int>>& M, int a, int i, int j, 
	std::vector<std::vector<int>> *R = NULL);

void rowSwap (std::vector<std::vector<int>>& M, int i, int j, 
	std::vector<std::vector<int>> *L = NULL);

void columnSwap (std::vector<std::vector<int>>& M, int i, int j, 
	std::vector<std::vector<int>> *R = NULL);

void killRowEntry (std::vector<std::vector<int>>& M, int columnIndex, int killerRowIndex, 
	int victimRowIndex, std::vector<std::vector<int>> *A=NULL);

std::vector<std::vector<int>> identity_matrix(int d);

void killLowerPart (std::vector<std::vector<int>>& M, int columnIndex, int rowIndex, 
	std::vector<std::vector<int>> *L=NULL);

void killColumnEntry (std::vector<std::vector<int>>& M, int rowIndex, int killerColumnIndex, 
	int victimColumnIndex, std::vector<std::vector<int>> *A=NULL);

void killRightPart (std::vector<std::vector<int>>& M, int rowIndex, int columnIndex, 
	std::vector<std::vector<int>> *A=NULL);

void CreateGCDinTopLeft (std::vector<std::vector<int>>& M, int leftColumnIndex, int rightColumnIndex,
	int stage, std::vector<std::vector<int>> *L=NULL, std::vector<std::vector<int>> *R=NULL);

void ComputeSmithNormalForm (std::vector<std::vector<int>>& M, std::vector<std::vector<int>> *L=NULL, 
	std::vector<std::vector<int>> *R=NULL);

}

#endif
