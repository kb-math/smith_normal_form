#include "matrixOperations.h"


//matrix and vector functions
std::vector<int> add(const std::vector<int>& v, const std::vector<int>& w) {
    std::vector<int> sum;
    sum.reserve(v.size());
    std::cout << std::endl;
    for(int i=0; i<v.size(); i++) {
            sum.push_back(v[i]+w[i]);}
    return sum;
}

std::vector<int> scale(int a, const std::vector<int>& v) {
    std::vector<int> scaled;
    scaled.reserve(v.size());
    for(int i=0; i<v.size(); i++) {
            scaled.push_back(a * v[i]);}
    return scaled;
}

Matrix<int> IdentityMatrix(int d) {
    Matrix<int> I;
    for (int i=0; i<d; i++) {
        I.push_back({});
        for (int j=0; j<d; j++) {
                I[i].push_back(i==j);
        }
    }
    return I;
}

//add a times row i to row j
void rowAdd (Matrix<int>& M, int a, int i, int j, 
    Matrix<int> *L) {

    M[j]=add(scale(a,M[i]),M[j]);
    if (L !=NULL) {
        (*L)[j]=add(scale(a,(*L)[i]),(*L)[j]);
    }
}

void columnAdd (Matrix<int>& M, int a, int i, int j, 
    Matrix<int> *R) {

    for (int k=0; k<M.GetHeight(); k++) {
        M[k][j]=a*(M[k][i])+M[k][j];
    }
    if (R != NULL) {
        for (int k=0; k<(*R).GetHeight(); k++) {
        (*R)[k][j]=a*((*R)[k][i])+(*R)[k][j];
    }
    }
}

void rowSwap (Matrix<int>& M, int i, int j, Matrix<int> *L) {
    std::swap(M[i], M[j]);
    if (L != NULL) {
        std::swap((*L)[i], (*L)[j]);
    }
}

void columnSwap (Matrix<int>& M, int i, int j, Matrix<int> *R) {
    for (int k=0; k<M.GetHeight(); k++) {
        std::swap (M[k][j], M[k][i]);}
    if (R != NULL) {
        for (int k=0; k<(*R).GetHeight(); k++) {
            std::swap ((*R)[k][j], (*R)[k][i]);}
    }
}
