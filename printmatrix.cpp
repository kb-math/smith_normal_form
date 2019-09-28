#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "printmatrix.h"

void PrintMatrix (const Matrix<int>& M) {
    int fatness = EntryFatness(M);
    for (int rowIndex = 0; rowIndex < M.GetHeight(); rowIndex++ ) {
        const std::vector<int>& row = M[rowIndex];
        for (int x: row) {
            if (x>=0) {
                std::cout << " "; // extra space for lack of minus sign.
            }
            std::cout << " " << x;
            for (int i=0; i < fatness - DigitLength(x); i++) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n \n";
}

int DigitLength (int a) { // returns number of digits of a.
    if (a < 0){
        a = -a;}
    if (a == 0){
        return 1;
    }
    else {
        return 1 + floor(log10(a));}
}

int EntryFatness (const Matrix<int>& M) {
    int currentMax = 1;
    for (int rowIndex = 0; rowIndex < M.GetHeight(); rowIndex++ ) {
        const std::vector<int>& row = M[rowIndex];
        for (int x: row) {
            int t = DigitLength(x);
            if (currentMax < t) {
                currentMax = t;}
            }
        }
    return currentMax;}
