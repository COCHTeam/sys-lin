#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

void create_next_matrix(Matrix & A_n, vector<Matrix> & A);

bool test_matrix();

int main() {
    int size = 3;
    auto A_0 = Matrix(size);
    A_0.set(0,0,2);
    A_0.set(0,1,-1);
    A_0.set(0,2,0);
    A_0.set(1,0,-1);
    A_0.set(1,1,2);
    A_0.set(1,2,-1);
    A_0.set(2,0,0);
    A_0.set(2,1,-1);
    A_0.set(2,2,2);
    A_0.print();
    Matrix L = Matrix(size);
    A_0.print();
    vector<Matrix> A={A_0};
    A_0.print();
    for (int n = 0; n < size; n++) {
        L.set(n,n,1);
        for (int i = 0; i < size; i++) {
            L.set(i,n,-A[n].get(i,n)/A[n].get(n,n));
        }
        A.push_back(L.multiply(A[n]));
    }

    return 0;
}

bool test_matrix() {
    auto A = Matrix(2);
    auto B = Matrix(2);
    auto C=Matrix(2);
    int **a;
    a = new int*[2];
    a[0] = new int[2];
    a[1] = new int[2];
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    A.set(a);
    B.set(0,0,5);
    B.set(0,1,6);
    B.set(1,0,7);
    B.set(1,1,8);
    C.set(0,0,19);
    C.set(0,1,22);
    C.set(1,0,43);
    C.set(1,1,50);
    return C==A.multiply(B);
}