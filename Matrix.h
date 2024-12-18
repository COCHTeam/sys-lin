//
// Created by droeurUser on 18/12/2024.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>


class Matrix {
    std::vector<std::vector<int>> matrix;
public:
    Matrix(int size);
    void print() const;
};



#endif //MATRIX_H
