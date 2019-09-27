#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "printmatrix.h"

void PrintMatrix (std::vector<std::vector<int>> M) {
    int fatness = EntryFatness(M);
    for (std::vector<int> row : M ) {
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

//TODO: this doesn't take fatness into account
void PrintAugMatrix(std::vector<std::vector<int>> M, std::vector<std::vector<int>> A) {
    int columnLength = M.size();
    for (int i = 0; i < columnLength; i++) {
        for (int x: M[i]) {
            std::cout << " " << x << " ";
        }
        std::cout << "|";
        for (int x: A[i]) {
            std::cout << " " << x << " ";
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

int EntryFatness (std::vector<std::vector<int>> M) {
    int currentMax = 1;
    for (std::vector<int> row: M) {
        for (int x: row) {
            int t = DigitLength(x);
            if (currentMax < t) {
                currentMax = t;}
            }
        }
    return currentMax;}


