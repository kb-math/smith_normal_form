#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "matrix/matrix.hpp"
#include "matrix/matrixOperations.h"

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
