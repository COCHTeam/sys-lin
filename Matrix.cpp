//
// Created by droeurUser on 18/12/2024.
//

#include "Matrix.h"

#include <iostream>
#include <vector>

Matrix::Matrix(const int size) {
    matrix=std::vector<std::vector<int>>(size);
    for (int i = 0; i < size; i++) {
        std::vector<int> _row(size);
        matrix.push_back(_row);
    }
}

void Matrix::print() const {
    for (const auto & i : matrix) {
        for (const int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
