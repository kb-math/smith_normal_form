#include <vector>

template <typename T>
class Matrix
{
public:
	Matrix(std::vector<std::vector<T>> M) {
		matrix_ = M;
	}

	std::vector<T>& operator[] (int rowIndex) {
		return matrix_[rowIndex];
	}

	unsigned int GetWidth() {
		return matrix_[0].size();
	}

	unsigned int GetHeight() {
		return matrix_.size();
	}

private:
	std::vector<std::vector<T>> matrix_;
};
