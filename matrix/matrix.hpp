#ifndef MATRIX_HPP
#define MATRIX_HPP

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

#endif
