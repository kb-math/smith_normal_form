#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int remainder(int a, int b) { // returns 0<= r <b such that r=a mod b
    if ( b<0) {
        b=-b;
    }
    if ( a<0 ) {
        return (a%b)+b;
    }
    return a%b;
}

int quotient(int a, int b) { // returns q where a=q*b+r where 0<=r<b.
    return (a - remainder(a,b))/b;
    }

//matrix and vector functions

vector<vector<int>> identity_matrix(int d) {
    vector<vector<int>> I;
    I.resize(d);
    for (int i=0; i<d; i++) {
        for (int j=0; j<d; j++) {
                I[i].push_back(i==j);
        }
    }
    return I;
}

vector<int> add(vector<int> v, vector<int> w) {
    for(int i=0; i<v.size(); i++) {
            v[i]=v[i]+w[i];}
    return v;
}

vector<int> scale(int a, vector<int> v) {
    for(int i=0; i<v.size(); i++) {
            v[i]=a*v[i];}
    return v;
}

vector<vector<int>> transpose (vector<vector<int>> M) {
    int len_row=M[0].size();
    int len_col=M.size();
    vector<vector<int>> Mt;
    Mt.resize(len_row);
    vector<int> curr_col;
    curr_col.resize(len_col);
    for (int i=0; i<len_row; i++) {
            for (int j=0; j<len_col; j++) {
                curr_col[j]=M[j][i];
            }
            Mt[i]=curr_col;
    }
    return Mt;
}


void rowadd (vector<vector<int>> *M, int a, int i, int j, vector<vector<int>> *L = NULL) { //add a times row i to row j.
    (*M)[j]=add(scale(a,(*M)[i]),(*M)[j]);
    if (L !=NULL) {
        (*L)[j]=add(scale(a,(*L)[i]),(*L)[j]);
    }
}

void coladd (vector<vector<int>> *M, int a, int i, int j, vector<vector<int>> *R = NULL) {
    for (int k=0; k<(*M).size(); k++) {
        (*M)[k][j]=a*((*M)[k][i])+(*M)[k][j];
    }
    if (R != NULL) {
        for (int k=0; k<(*R).size(); k++) {
        (*R)[k][j]=a*((*R)[k][i])+(*R)[k][j];
    }
    }
}

void rowswap (vector<vector<int>> *M, int i, int j, vector<vector<int>> *L = NULL) {
    swap((*M)[i], (*M)[j]);
    if (L != NULL) {
        swap((*L)[i], (*L)[j]);
    }
}

void colswap (vector<vector<int>> *M, int i, int j, vector<vector<int>> *R = NULL) {
    for (int k=0; k<(*M).size(); k++) {
        swap ((*M)[k][j], (*M)[k][i]);}
    if (R != NULL) {
        for (int k=0; k<(*R).size(); k++) {
            swap ((*R)[k][j], (*R)[k][i]);}
    }
}



void kill_row_entry (vector<vector<int>> *M, int col_ind, int row_top, int row_aim, vector<vector<int>> *L=NULL) {
    int q;
    while ( (*M)[row_aim][col_ind] != 0 ) {
        q=quotient((*M)[row_top][col_ind] ,(*M)[row_aim][col_ind]);
        rowadd(M, -q, row_aim, row_top, L);
        rowswap(M, row_top, row_aim, L);
    }
}

void kill_lower_part (vector<vector<int>> *M, int row_ind, int col_ind, vector<vector<int>> *L=NULL) {
    for (int i=row_ind+1; i<(*M).size(); i++) {
        kill_row_entry(M, col_ind, row_ind, i , L);
    }
    }

void kill_col_entry (vector<vector<int>> *M, int row_ind, int col_left, int col_aim, vector<vector<int>> *R=NULL) {
    int q;
    while ( (*M)[row_ind][col_aim] != 0 ) {
        q=quotient((*M)[row_ind][col_left] ,(*M)[row_ind][col_aim]);
        coladd(M, -q, col_aim, col_left, R);
        colswap(M, col_left, col_aim, R);
    }
}

void kill_right_part (vector<vector<int>> *M, int row_ind, int col_ind, vector<vector<int>> *A=NULL) {
    for (int i=col_ind+1; i<(*M)[0].size(); i++) {
        kill_col_entry(M, row_ind, col_ind,i , A);}
}

void gcd_two_cols (vector<vector<int>> *M, int col_1, int col_2, int stage, vector<vector<int>> *L=NULL, vector<vector<int>> *R=NULL) {
    while (1==1) {
        kill_lower_part(M, stage, col_1, L);
        if ((*M)[stage][col_2]==0) {
            break;
        } else {
            kill_col_entry(M, stage, col_1, col_2, R);
            }
    }
    // The following part complicates things, only necessary in pathological cases. Write an if part which checks for the pathology.
    coladd(M, 1, col_2, col_1, R);
    kill_lower_part(M, stage, col_1, L);
    }

void final_form (vector<vector<int>> *M, vector<vector<int>> *L=NULL, vector<vector<int>> *R=NULL) {
    int width_M=(*M)[0].size();
    int height_M=(*M).size();
    for (int stage=0; ((stage<width_M) && (stage<height_M)); stage++ ) {
            for (int i=stage+1; i<width_M; i++ ) {
                gcd_two_cols (M, stage, i, stage, L, R);}

        if ((*M)[stage][stage]==0) {return; }
        for (int i=stage+1; i<width_M; i++ ) {
            int q=((*M)[stage][i])/((*M)[stage][stage]);
            coladd(M, -q, stage, i, R);}
    }

}
