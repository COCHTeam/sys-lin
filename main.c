#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

void create_next_matrix(Matrix* A_n, Matrix** A);

bool test_matrix();

int main() {
    printf("Pass test : %d\n\n", test_matrix());
    const int size = 3;
    Matrix* A_0 = MatrixBuilder(size);
    MatrixSetAt(A_0, 0,0,2);
    MatrixSetAt(A_0,0,1,-1);
    MatrixSetAt(A_0,0,2,0);
    MatrixSetAt(A_0,1,0,-1);
    MatrixSetAt(A_0,1,1,2);
    MatrixSetAt(A_0,1,2,-1);
    MatrixSetAt(A_0,2,0,0);
    MatrixSetAt(A_0,2,1,-1);
    MatrixSetAt(A_0,2,2,2);
    Matrix** A = malloc(sizeof(Matrix)*size);
    A[0]=A_0;
    MatrixPrint(A[0]);
    for (int n = 0; n < size-1; n++) {
        Matrix* L = MatrixBuilder(size);
        MatrixSetAt(L,n,n,1);
        for (int i = 0; i < size; i++) {
            MatrixSetAt(L,i,n,-MatrixGetAt(A[n],i,n)/MatrixGetAt(A[n],n,n));
        }
        A[n+1]=MatrixMultiply(L,A[n]);
        MatrixDestroyer(L);
    }
    MatrixPrint(A[size-1]);
    free(A);
    return 0;
}

bool test_matrix() {
    Matrix* A = MatrixBuilder(2);
    Matrix* B = MatrixBuilder(2);
    Matrix* C=MatrixBuilder(2);
    double **a=malloc(sizeof(double*)*2);
    for(int i=0;i<2;i++) {
        a[i]=calloc(2,sizeof(double));
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    MatrixSetWhole(A,a);
    free(a);

    MatrixSetAt(B,0,0,5);
    MatrixSetAt(B,0,1,6);
    MatrixSetAt(B,1,0,7);
    MatrixSetAt(B,1,1,8);

    MatrixSetAt(C,0,0,19);
    MatrixSetAt(C,0,1,22);
    MatrixSetAt(C,1,0,43);
    MatrixSetAt(C,1,1,50);

    bool equals = MatrixEqual(C,MatrixMultiply(A,B));

    MatrixDestroyer(A);
    MatrixDestroyer(B);
    MatrixDestroyer(C);
    return equals;
}