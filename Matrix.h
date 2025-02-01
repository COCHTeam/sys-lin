//
// Created by droeurUser on 18/12/2024.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

typedef struct {
    double** _mat;
    int _size;
} Matrix;

Matrix* MatrixBuilder(int size);
void MatrixDestroyer(Matrix* matrix);

void MatrixPrint(Matrix* matrix);
[[nodiscard]] inline int MatrixSize(const Matrix* mat) { return mat->_size; }

void MatrixSetAt(Matrix* matrix, int i, int j, double value);
void MatrixSetWhole(Matrix* matrix, double** array);
double MatrixGetAt(const Matrix* matrix, int i, int j);

Matrix* MatrixMultiply(const Matrix* first,const Matrix* second);
bool MatrixEqual(const Matrix *first, const Matrix *second);


#endif //MATRIX_H
