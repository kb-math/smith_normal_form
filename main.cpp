#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "snf_header.h"

using namespace std;

struct snf_data {
        vector<vector<int>> L;
        vector<vector<int>> D;
        vector<vector<int>> R;
    };

snf_data smith_normal_form (vector<vector<int>> M) {
    int width = M[0].size();
    int height = M.size();
    vector<vector<int>>L=identity_matrix(height);
    vector<vector<int>>R=identity_matrix(width);

    final_form(&M,&L,&R);


    snf_data SNF= {L,M,R};

    return SNF;}

int main(){

    vector<vector<int>> A;

    A={{1,1,5},{1,-1,3}}; // A = {row_1, row_2, row_3, ..., row_n}, edit as you please! A does NOT have to be square.

    // We will find invertible integer matrices L and R (with integer inverses)
    // such that D=LAR is diagonal and each diagonal entry of D divides the next.

    snf_data SNF_A = smith_normal_form (A);

    vector<vector<int>> L=SNF_A.L;
    vector<vector<int>> D=SNF_A.D;
    vector<vector<int>> R=SNF_A.R;

    //We can now print L, R, and D,

    cout << "L = \n\n";
    print_matrix(L);

    cout << "R = \n\n";
    print_matrix(R);

    cout << "D = \n\n";
    print_matrix(D);










    return 0;
    }



