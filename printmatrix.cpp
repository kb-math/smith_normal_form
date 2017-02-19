#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int digit_len (int a) { // returns number of digits of a.
    if (a<0){
        a=-a;}
    if (a==0){
        return 1;
    }
    else {
        return 1+floor(log10(a));}
}

int my_max(vector<int> v) {
    int cur_max=v[0];
    for (int i=1; i<v.size(); i++) {
            if (v[i]>cur_max) {
                cur_max=v[i];
            }}
    return cur_max;}

int entry_fatness(vector<vector<int>> M) {
    int cur_max=1;
    for (vector<int> row: M) {
        for (int x: row) {
            int t=digit_len(x);
            if (cur_max < t) {
                cur_max=t;}
            }
        }
    return cur_max;}


void print_matrix (vector<vector<int>> M) {
    int fatness = entry_fatness(M);
    for (vector<int> row : M ) {
        for (int x: row) {
            if (x>=0) {
                cout << " "; // extra space for lack of minus sign.
            }
            cout << " " << x;
            for (int i=0; i<fatness - digit_len(x); i++) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n \n";
    }

void print_aug_matrix (vector<vector<int>> M, vector<vector<int>> A) {
    int col_len=M.size();
    for (int i=0; i<col_len; i++) {
        for (int x: M[i]) {
            cout << " " << x << " ";
        }
        cout << "|";
        for (int x: A[i]) {
            cout << " " << x << " ";
        }
        cout << "\n";
    }
    cout << "\n \n";
    }
