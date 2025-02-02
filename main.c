#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

bool test_matrix();

int main() {
    // On effectue un test préliminaire
    printf("Pass test : %d\n\n", test_matrix());

    // On initialise la matrice A_0
    //        2 -1  0
    // A_0 = -1  2 -1
    //        0 -1  2
    const int size = 4;
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

    MatrixSetAt(A_0,0,3,5);
    MatrixSetAt(A_0,3,0,5);
    MatrixSetAt(A_0,1,3,3);
    MatrixSetAt(A_0,3,1,3);
    MatrixSetAt(A_0,2,3,2);
    MatrixSetAt(A_0,3,2,2);
    MatrixSetAt(A_0,3,3,4);

    // On crée la liste des matrice A_n
    Matrix** A = malloc(sizeof(Matrix)*size);

    // On initalise la première matrice de la liste
    A[0]=A_0;
    MatrixPrint(A[0]);

    // L'algorithme en question : on trouve le L et le U par récurrence en faisant le produit : A_n+1 = L_n*A_n avec:
    //        1  0       0
    // L_n =  * -l_n+1,n 0
    //        * -l_N,n   1
    // Avec l_i,n= a_i,n/a_n,n
    // Une fois qu'on aura finit la recurrence, on aura le L_final = (L_N*...*L_2*L_1)^-1 et A_n sera le U : A=L*U
    // Or, on remarque que (L_N*...*L_2*L_1)^-1 = L_1+L_2+...+L_N-(N-1)I

    Matrix* L_final = MatrixBuilder(size);// Pour garder le L final
    MatrixSetOne(L_final); // Matrice unitée

    for (int n = 0; n < size-1; n++) {
        Matrix* L_n = MatrixBuilder(size); // On initialise un nouveau L
        MatrixSetOne(L_n); // Pour faire que la diagonale soit 1
        for (int i = n+1; i < size; i++) {
            double l_in=-MatrixGetAt(A[n],i,n)/MatrixGetAt(A[n],n,n); // on calcule l_i,n si i>n, c'est à dire SOUS la diagonale
            MatrixSetAt(L_n,i,n,l_in); // on place ici l_i,n
        }

        printf("L_%d:\n",n);
        MatrixPrint(L_n);

        // On fait le produit A_n+1 = L*A_n
        A[n+1]=MatrixMultiply(L_n,A[n]);
        L_final=MatrixAdd(L_final, L_n);
    }
    // On a ici L_final = L_1+L_2+...*l_n, on va donc faire L_final = -L_final puis mettre des 1 sur la diagonale
    MatrixOppose(L_final);
    for (int i = 0; i < size; i++) {
        MatrixSetAt(L_final,i,i,1);
    }

    // On print le resultat
    printf("A=LU :\n");
    MatrixPrint(A[0]);
    printf("=\n");
    MatrixPrint(L_final);
    printf("*\n");
    MatrixPrint(A[size-1]);

    // On free tout
    for(int n = 0; n < size; n++) {
        free(A[n]);
    }

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