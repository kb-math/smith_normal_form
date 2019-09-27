#include "matrix.h"

Matrix::Matrix(std::vector<std::vector<int>> M) {
	matrix_ = M;
}

std::vector<int>& Matrix::operator[] (int rowIndex) {
	return matrix_[rowIndex];
}

unsigned int Matrix::GetWidth() {
	return matrix_[0].size();
}

unsigned int Matrix::GetHeight() {
	return matrix_.size();
}
