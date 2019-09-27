#include <vector>

class Matrix
{
public:
	Matrix(std::vector<std::vector<int>> M);

	std::vector<int>& operator[] (int rowIndex);

	unsigned int GetWidth();
	unsigned int GetHeight();

private:
	std::vector<std::vector<int>> matrix_;
};
