//
// Created by droeurUser on 18/12/2024.
//

#include "Matrix.h"

#include <iostream>
#include <cstring>

using namespace std;

Matrix::Matrix(const int size) {
    _size=size;
    _mat=new int*[size];
    for (int i = 0; i < size; i++) {
        const auto _row = new int[size];
        memset( _row, 0, sizeof(int)*size);
        _mat[i]=_row;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < _size; i++) {
        delete[] _mat[i];
    }
    delete[] _mat;
}

void Matrix::print() const {
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            std::cout << _mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::set(const int i, const int j, const int value) const {
    _mat[i][j] = value;
}

void Matrix::set(int **array) const {
    if(array==nullptr || sizeof(array)/sizeof(int)!=_size) {
        cerr<<"Matrix::set: Size error: Matrix size("<<_size << ")!=Array size("<<sizeof(array)/sizeof(int)<<")"<<endl;
        return;
    }
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            _mat[i][j] = array[i][j];
        }
    }
}

int Matrix::get(int i, int j) {
    if(i>=0 && i<this->size() && j>=0 && j<this->size()) {
        return _mat[i][j];
    }
    cerr<<"Matrix::get: Invalid index"<<endl;
    return 0;
}

Matrix Matrix::multiply(const Matrix &rhs) const {
    Matrix result(_size);
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            int sum=0;
            for (int k = 0; k < this->size(); k++) {
                sum += this->_mat[i][k] * rhs._mat[k][j];
            }
            result.set(i,j,sum);
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix &rhs) const {
    if (this->size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            if (_mat[i][j] != rhs._mat[i][j]) {
                return false;
            }
        }
    }
    return true;
}
