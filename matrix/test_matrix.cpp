#include <iostream>
#include "matrix.h"

int main() {

	Matrix<int> testMatrix(
		{
			{1,2,3},
			{4,5,6},
			{7,8,9}
		});

	testMatrix[1][1] = testMatrix[0][0] + testMatrix[2][2] -1;

	testMatrix[0][2] *= 2;
	testMatrix[0][0]++;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << testMatrix[i][j] << " ";
		}

		std::cout << "\n";
	}

	return 0;
}