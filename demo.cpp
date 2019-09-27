#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "printmatrix.h"
#include "snf_header.h"

struct snf_data {
        std::vector<std::vector<int>> L;
        std::vector<std::vector<int>> D;
        std::vector<std::vector<int>> R;
    };

snf_data smith_normal_form (std::vector<std::vector<int>> M) {
    int width = M[0].size();
    int height = M.size();
    std::vector<std::vector<int>>L = SmithNormalFormCalculator::identity_matrix(height);
    std::vector<std::vector<int>>R = SmithNormalFormCalculator::identity_matrix(width);

    SmithNormalFormCalculator::ComputeSmithNormalForm(&M,&L,&R);


    snf_data SNF= {L,M,R};

    return SNF;}

int main(){

    std::vector<std::vector<int>> A;

    // A = {row_1, row_2, row_3, ..., row_n}, edit as you please! A does NOT have to be square.
    A={{1,1,5},{1,-1,3}};

    // We will find invertible integer matrices L and R (with integer inverses)
    // such that D=LAR is diagonal and each diagonal entry of D divides the next.

    snf_data SNF_A = smith_normal_form (A);

    std::vector<std::vector<int>> L=SNF_A.L;
    std::vector<std::vector<int>> D=SNF_A.D;
    std::vector<std::vector<int>> R=SNF_A.R;

    //We can now print L, R, and D,

    std::cout << "L = \n\n";
    PrintMatrix(L);

    std::cout << "R = \n\n";
    PrintMatrix(R);

    std::cout << "D = \n\n";
    PrintMatrix(D);

    return 0;
    }



