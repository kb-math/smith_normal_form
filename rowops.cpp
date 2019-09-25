#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

namespace SmithNormalFormCalculator {

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

std::vector<std::vector<int>> identity_matrix(int d) {
    std::vector<std::vector<int>> I;
    I.resize(d);
    for (int i=0; i<d; i++) {
        for (int j=0; j<d; j++) {
                I[i].push_back(i==j);
        }
    }
    return I;
}

std::vector<int> add(std::vector<int> v, std::vector<int> w) {
    for(int i=0; i<v.size(); i++) {
            v[i]=v[i]+w[i];}
    return v;
}

std::vector<int> scale(int a, std::vector<int> v) {
    for(int i=0; i<v.size(); i++) {
            v[i]=a * v[i];}
    return v;
}

std::vector<std::vector<int>> transpose (std::vector<std::vector<int>> M) {
    int len_row=M[0].size();
    int len_col=M.size();
    std::vector<std::vector<int>> Mt;
    Mt.resize(len_row);
    std::vector<int> curr_col;
    curr_col.resize(len_col);
    for (int i=0; i<len_row; i++) {
            for (int j=0; j<len_col; j++) {
                curr_col[j]=M[j][i];
            }
            Mt[i]=curr_col;
    }
    return Mt;
}

//add a times row i to row j
void rowadd (std::vector<std::vector<int>> *M, int a, int i, int j, 
    std::vector<std::vector<int>> *L = NULL) {

    (*M)[j]=add(scale(a,(*M)[i]),(*M)[j]);
    if (L !=NULL) {
        (*L)[j]=add(scale(a,(*L)[i]),(*L)[j]);
    }
}

void coladd (std::vector<std::vector<int>> *M, int a, int i, int j, 
    std::vector<std::vector<int>> *R = NULL) {

    for (int k=0; k<(*M).size(); k++) {
        (*M)[k][j]=a*((*M)[k][i])+(*M)[k][j];
    }
    if (R != NULL) {
        for (int k=0; k<(*R).size(); k++) {
        (*R)[k][j]=a*((*R)[k][i])+(*R)[k][j];
    }
    }
}

void rowswap (std::vector<std::vector<int>> *M, int i, int j, std::vector<std::vector<int>> *L = NULL) {
    std::swap((*M)[i], (*M)[j]);
    if (L != NULL) {
        std::swap((*L)[i], (*L)[j]);
    }
}

void colswap (std::vector<std::vector<int>> *M, int i, int j, std::vector<std::vector<int>> *R = NULL) {
    for (int k=0; k<(*M).size(); k++) {
        std::swap ((*M)[k][j], (*M)[k][i]);}
    if (R != NULL) {
        for (int k=0; k<(*R).size(); k++) {
            std::swap ((*R)[k][j], (*R)[k][i]);}
    }
}



void killRowEntry (std::vector<std::vector<int>> *M, int columnIndex, int killerRowIndex, 
    int victimRowIndex, std::vector<std::vector<int>> *L=NULL) {

    int q;
    while ( (*M)[victimRowIndex][columnIndex] != 0 ) {
        q=quotient((*M)[killerRowIndex][columnIndex] ,(*M)[victimRowIndex][columnIndex]);
        rowadd(M, -q, victimRowIndex, killerRowIndex, L);
        rowswap(M, killerRowIndex, victimRowIndex, L);
    }
}

void killLowerPart (std::vector<std::vector<int>> *M, int rowIndex, int columnIndex, 
    std::vector<std::vector<int>> *L=NULL) {

    for (int i=rowIndex+1; i<(*M).size(); i++) {
        killRowEntry(M, columnIndex, rowIndex, i , L);
    }
    }

void killColumnEntry (std::vector<std::vector<int>> *M, int rowIndex, int killerColumnIndex, 
    int victimColumnIndex, std::vector<std::vector<int>> *R=NULL) {

    int q;
    while ( (*M)[rowIndex][victimColumnIndex] != 0 ) {
        q=quotient((*M)[rowIndex][killerColumnIndex] ,(*M)[rowIndex][victimColumnIndex]);
        coladd(M, -q, victimColumnIndex, killerColumnIndex, R);
        colswap(M, killerColumnIndex, victimColumnIndex, R);
    }
}

void killRightPart (std::vector<std::vector<int>> *M, int rowIndex, int columnIndex, 
    std::vector<std::vector<int>> *A=NULL) {
    for (int i=columnIndex+1; i<(*M)[0].size(); i++) {
        killColumnEntry(M, rowIndex, columnIndex,i , A);}
}

void CreateGCDinTopLeft (std::vector<std::vector<int>> *M, int leftColumnIndex, int rightColumnIndex, 
    int stage, std::vector<std::vector<int>> *L=NULL, std::vector<std::vector<int>> *R=NULL) {

    while (true) {
        killLowerPart(M, stage, leftColumnIndex, L);
        if ((*M)[stage][rightColumnIndex]==0) {
            break;
        } else {
            killColumnEntry(M, stage, leftColumnIndex, rightColumnIndex, R);
            }
    }
    coladd(M, 1, rightColumnIndex, leftColumnIndex, R);
    killLowerPart(M, stage, leftColumnIndex, L);
    }

void ComputeSmithNormalForm (std::vector<std::vector<int>> *M, 
    std::vector<std::vector<int>> *L=NULL, std::vector<std::vector<int>> *R=NULL) {

    int width_M=(*M)[0].size();
    int height_M=(*M).size();
    for (int stage=0; ((stage<width_M) && (stage<height_M)); stage++ ) {
            for (int i=stage+1; i<width_M; i++ ) {
                CreateGCDinTopLeft (M, stage, i, stage, L, R);}

        if ((*M)[stage][stage]==0) {
            return; 
        }
        for (int i=stage+1; i<width_M; i++ ) {
            int q=((*M)[stage][i])/((*M)[stage][stage]);
            coladd(M, -q, stage, i, R);}
    }
}

}
