#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

#include "printmatrix.h"

void print_matrix (std::vector<std::vector<int>> M) {
    int fatness = entry_fatness(M);
    for (std::vector<int> row : M ) {
        for (int x: row) {
            if (x>=0) {
                std::cout << " "; // extra space for lack of minus sign.
            }
            std::cout << " " << x;
            for (int i=0; i<fatness - digit_len(x); i++) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n \n";
}

//TODO: this doesn't take fatness into account
void print_aug_matrix (std::vector<std::vector<int>> M, std::vector<std::vector<int>> A) {
    int col_len=M.size();
    for (int i=0; i<col_len; i++) {
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
int digit_len (int a) { // returns number of digits of a.
    if (a<0){
        a=-a;}
    if (a==0){
        return 1;
    }
    else {
        return 1+floor(log10(a));}
}

int entry_fatness(std::vector<std::vector<int>> M) {
    int cur_max=1;
    for (std::vector<int> row: M) {
        for (int x: row) {
            int t=digit_len(x);
            if (cur_max < t) {
                cur_max=t;}
            }
        }
    return cur_max;}


