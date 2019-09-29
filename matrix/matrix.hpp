#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

// implementing a matrix where the coefficients form a Ring
// https://en.wikipedia.org/wiki/Ring_(mathematics)

template <typename Ring>
class Matrix
{
public:
	Matrix() {}

	Matrix(std::vector<std::vector<Ring>> M) {
		matrix_ = M;
	}

	Matrix(unsigned int rowCount) {
		matrix_.reserve(rowCount);
	}

	void push_back(std::vector<Ring> row) {
		matrix_.push_back(row);
	}

	std::vector<Ring>& operator[] (int rowIndex) {
		return matrix_[rowIndex];
	}

	const std::vector<Ring>& operator[] (int rowIndex) const {
		return matrix_[rowIndex];
	}

	unsigned int GetWidth() const {
		return matrix_[0].size();
	}

	unsigned int GetHeight() const {
		return matrix_.size();
	}

private:
	std::vector<std::vector<Ring>> matrix_;
};

// matrix arithmetic

template<typename Ring>
Matrix<Ring> operator*(const Matrix<Ring>& A, const Matrix<Ring>& B) {
	// the number of rows of product is the number of rows in the first matrix A, hence
	// reserve this much size
	// TODO: does resize make more sense?
	Matrix<Ring> productMatrix(A.GetHeight());

	//throw if matrix product undefined?
	if (A.GetWidth() != B.GetHeight()) {
		throw;
	}

	for (int rowIndex = 0; rowIndex < A.GetHeight(); rowIndex++) {
		//TODO: reserve the size of the row for efficiency
		productMatrix.push_back({});
		for (int columnIndex = 0; columnIndex < B.GetWidth(); columnIndex++) {
			// construct the rowIndex, columnIndex entry of product matrix here
			Ring newEntry = 0;
			for (int i=0; i < A.GetWidth(); i++) {
				newEntry += A[rowIndex][i] * B[i][columnIndex];
			}

			productMatrix[rowIndex].push_back(newEntry);
		}
	}

	return productMatrix;
}

#endif
