#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "matrix/matrix.hpp"

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

Matrix<int> identity_matrix(int d) {
    Matrix<int> I;
    for (int i=0; i<d; i++) {
        I.push_back({});
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

//add a times row i to row j
void rowAdd (Matrix<int>& M, int a, int i, int j, 
    Matrix<int> *L = NULL) {

    M[j]=add(scale(a,M[i]),M[j]);
    if (L !=NULL) {
        (*L)[j]=add(scale(a,(*L)[i]),(*L)[j]);
    }
}

void columnAdd (Matrix<int>& M, int a, int i, int j, 
    Matrix<int> *R = NULL) {

    for (int k=0; k<M.GetHeight(); k++) {
        M[k][j]=a*(M[k][i])+M[k][j];
    }
    if (R != NULL) {
        for (int k=0; k<(*R).GetHeight(); k++) {
        (*R)[k][j]=a*((*R)[k][i])+(*R)[k][j];
    }
    }
}

void rowSwap (Matrix<int>& M, int i, int j, Matrix<int> *L = NULL) {
    std::swap(M[i], M[j]);
    if (L != NULL) {
        std::swap((*L)[i], (*L)[j]);
    }
}

void columnSwap (Matrix<int>& M, int i, int j, Matrix<int> *R = NULL) {
    for (int k=0; k<M.GetHeight(); k++) {
        std::swap (M[k][j], M[k][i]);}
    if (R != NULL) {
        for (int k=0; k<(*R).GetHeight(); k++) {
            std::swap ((*R)[k][j], (*R)[k][i]);}
    }
}



void killRowEntry (Matrix<int>& M, int columnIndex, int killerRowIndex, 
    int victimRowIndex, Matrix<int> *L=NULL) {

    int q;
    while ( M[victimRowIndex][columnIndex] != 0 ) {
        q=quotient(M[killerRowIndex][columnIndex] ,M[victimRowIndex][columnIndex]);
        rowAdd(M, -q, victimRowIndex, killerRowIndex, L);
        rowSwap(M, killerRowIndex, victimRowIndex, L);
    }
}

void killLowerPart (Matrix<int>& M, int rowIndex, int columnIndex, 
    Matrix<int> *L=NULL) {

    for (int i=rowIndex+1; i<M.GetHeight(); i++) {
        killRowEntry(M, columnIndex, rowIndex, i , L);
    }
    }

void killColumnEntry (Matrix<int>& M, int rowIndex, int killerColumnIndex, 
    int victimColumnIndex, Matrix<int> *R=NULL) {

    int q;
    while ( M[rowIndex][victimColumnIndex] != 0 ) {
        q=quotient(M[rowIndex][killerColumnIndex] ,M[rowIndex][victimColumnIndex]);
        columnAdd(M, -q, victimColumnIndex, killerColumnIndex, R);
        columnSwap(M, killerColumnIndex, victimColumnIndex, R);
    }
}

void killRightPart (Matrix<int>& M, int rowIndex, int columnIndex, 
    Matrix<int> *A=NULL) {
    for (int i=columnIndex+1; i<M.GetWidth(); i++) {
        killColumnEntry(M, rowIndex, columnIndex,i , A);}
}

void CreateGCDinTopLeft (Matrix<int>& M, int leftColumnIndex, int rightColumnIndex, 
    int stage, Matrix<int> *L=NULL, Matrix<int> *R=NULL) {

    while (true) {
        killLowerPart(M, stage, leftColumnIndex, L);
        if (M[stage][rightColumnIndex]==0) {
            break;
        } else {
            killColumnEntry(M, stage, leftColumnIndex, rightColumnIndex, R);
            }
    }
    columnAdd(M, 1, rightColumnIndex, leftColumnIndex, R);
    killLowerPart(M, stage, leftColumnIndex, L);
    }

void ComputeSmithNormalForm (Matrix<int>& M, 
    Matrix<int> *L=NULL, Matrix<int> *R=NULL) {

    int width_M = M.GetWidth();
    int height_M = M.GetHeight();
    for (int stage=0; ((stage<width_M) && (stage<height_M)); stage++ ) {
            for (int i=stage+1; i<width_M; i++ ) {
                CreateGCDinTopLeft (M, stage, i, stage, L, R);}

        if (M[stage][stage]==0) {
            return; 
        }
        for (int i=stage+1; i<width_M; i++ ) {
            int q=(M[stage][i])/(M[stage][stage]);
            columnAdd(M, -q, stage, i, R);}
    }
}

}
