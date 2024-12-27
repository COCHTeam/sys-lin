//
// Created by droeurUser on 18/12/2024.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>


class Matrix {
    int** _mat;
    int _size;
public:
    explicit Matrix(int size);
    ~Matrix();
    void print() const;
    [[nodiscard]] int size() const { return _size; }

    void set(int i, int j, int value) const;
    void set(int** array) const;
    int get(int i, int j);
    [[nodiscard]] Matrix multiply(const Matrix& rhs) const;

    bool operator==(const Matrix& rhs) const;
};



#endif //MATRIX_H
