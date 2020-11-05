#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "matrix/matrix.hpp"
#include "matrix/matrixOperations.h"
#include "printmatrix.h"
#include "smithNormalForm.h"

int main(){

    // A = {row_1, row_2, row_3, ..., row_n}, edit as you please! A does NOT have to be square.
    Matrix<int> A({
        {1,  1, 5},
        {1, -1, 3}
    });

    // We will find invertible integer matrices L and R (with integer inverses)
    // such that D=LAR is diagonal and each diagonal entry of D divides the next.
    // TODO: actually more useful to decompose A = LDR instead

    SmithNormalFormDecomposition result = SmithNormalFormCalculator::ComputeSmithNormalForm(A);

    Matrix<int> L = std::move(result.L);
    Matrix<int> D = std::move(result.D);
    Matrix<int> R = std::move(result.R);

    //We can now print L, R, and D,

    std::cout << "A = \n\n";
    PrintMatrix(A);

    std::cout << "L = \n\n";
    PrintMatrix(L);

    std::cout << "R = \n\n";
    PrintMatrix(R);

    std::cout << "D = \n\n";
    PrintMatrix(D);

    // now multiply them together to see if the product is equal  
    std::cout << "L*A*R = \n\n";
    PrintMatrix(L*A*R); // it should equal to D  (TODO: this could be a unit test)

    return 0;
    }
    
