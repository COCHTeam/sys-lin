//
// Created by droeurUser on 18/12/2024.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix* MatrixBuilder(const int size) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->_size=size;
    matrix->_mat=malloc(size*sizeof(double*));
    for(int i=0;i<size;i++) {
        matrix->_mat[i]=calloc(size,sizeof(double));
    }
    return matrix;
}

void MatrixDestroyer(Matrix* matrix) {
    for (int i = 0; i < matrix->_size; i++) {
        free(matrix->_mat[i]);
    }
    free(matrix->_mat);
}

void MatrixCopy(Matrix *targetMatrix, Matrix *matrixToCopy) {
    for (int i = 0; i < targetMatrix->_size; i++) {
        for (int j = 0; j < targetMatrix->_size; j++) {
            targetMatrix->_mat[i][j] = matrixToCopy->_mat[i][j];
        }
    }
}

void MatrixSetOne(Matrix* matrix) {
    for (int i = 0; i < matrix->_size; i++) {
        matrix->_mat[i][i] = 1;
    }
}

void MatrixPrint(Matrix* matrix) {
    for (int i = 0; i < matrix->_size; i++) {
        for (int j = 0; j < matrix->_size; j++) {
            printf("%f ", matrix->_mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void MatrixSetAt(Matrix* matrix, int i, int j, double value) {
    matrix->_mat[i][j] = value;
}

void MatrixSetWhole(Matrix* matrix, double** array) {
    /*if(array==NULL || sizeof(array)/sizeof(array[0])*sizeof(array[0])/sizeof(array[0][0])!=matrix->_size) {
        printf("Matrix::set: Size error: Matrix size(%d)!=Array size(%llu)\n",matrix->_size,sizeof(array)/sizeof(array[0])*sizeof(array[0])/sizeof(array[0][0]));
        return;
    }*/
    for (int i = 0; i < matrix->_size; i++) {
        for (int j = 0; j < matrix->_size; j++) {
            MatrixSetAt(matrix,i,j,array[i][j]);
        }
    }
}

double MatrixGetAt(const Matrix* matrix, const int i, const int j) {
    if(i>=0 && i<matrix->_size && j>=0 && j<matrix->_size) {
        return matrix->_mat[i][j];
    }
    printf("Matrix::get: Invalid index");
    return 0;
}

Matrix* MatrixMultiply(const Matrix* first,const Matrix* second) {
    Matrix* result = MatrixBuilder(first->_size);
    for (int i = 0; i < first->_size; i++) {
        for (int j = 0; j < first->_size; j++) {
            double sum=0;
            for (int k = 0; k < first->_size; k++) {
                sum += first->_mat[i][k] * second->_mat[k][j];
            }
            MatrixSetAt(result,i,j,sum);
        }
    }
    return result;
}

Matrix * MatrixAdd(const Matrix *first, const Matrix *second) {
    Matrix* result = MatrixBuilder(first->_size);
    for (int i = 0; i < first->_size; i++) {
        for (int j = 0; j < first->_size; j++) {
            MatrixSetAt(result,i,j,first->_mat[i][j]+second->_mat[i][j]);
        }
    }
    return result;
}

void MatrixOppose(const Matrix *first) {
    for (int i = 0; i < first->_size; i++) {
        for (int j = 0; j < first->_size; j++) {
            if(first->_mat[i][j])
                first->_mat[i][j]=-first->_mat[i][j];
        }
    }
}

bool MatrixEqual(const Matrix *first, const Matrix *second) {
    if (first->_size != second->_size) {
        return false;
    }
    for (int i = 0; i < first->_size; i++) {
        for (int j = 0; j < first->_size; j++) {
            if (first->_mat[i][j] != second->_mat[i][j]) {
                return false;
            }
        }
    }
    return true;
}
