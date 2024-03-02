// Implementation part of a module for the Matrix class.
#include "matrix.h"
#include <stdexcept>


// TODO: provide here implementation of the Matrix class methods.
// Matrix::Matrix() : Matrix(0, 0, 0.0) {} // moved to the header file, because its just an initialization of the class object

Matrix::Matrix(size_t m, size_t n, double def): _matrix(m, MatrixVector(n, def)) {
}

void Matrix::resize(size_t m, size_t n, double def) {
    _matrix.resize(m, MatrixVector(n, def));
    for (auto& row : _matrix) {
        row.resize(n, def);
    }
}

Matrix::MatrixVector Matrix::createVector(size_t sz, double val) {
    return MatrixVector(sz, val);
}

Matrix::SizePair Matrix::getSize() const {
    return SizePair(_matrix.size(), _matrix[0].size());
}

Matrix::MatrixVector& Matrix::operator[](size_t i) {
    if (i >= _matrix.size()) {
        throw std::out_of_range("There is no such a row");
    }
    return _matrix[i];
}


const Matrix::MatrixVector& Matrix::operator[](size_t i) const {
    if (i >= _matrix.size()) {
        throw std::out_of_range("There is no such a row");
    }
    return _matrix[i];
}

double Matrix::getEl(size_t i, size_t j) const {
    if (i >= _matrix.size() || j >= _matrix[0].size()) {
        throw std::out_of_range("There is no such an element");
    }
    return _matrix[i][j];
}

void Matrix::setEl(size_t i, size_t j, double val) {
    if (i >= _matrix.size() || j >= _matrix[0].size()) {
        throw std::out_of_range("There is no such an element");
    }
    _matrix[i][j] = val;
}

bool Matrix::operator==(const Matrix& rhv) const {
    if (getSize() != rhv.getSize()) {
        return false;
    }
    for (size_t i = 0; i < getSize().first; ++i) {
        for (size_t j = 0; j < getSize().second; ++j) {
            if (getEl(i, j) != rhv.getEl(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& rhv) const {
    return !(*this == rhv);
}

Matrix Matrix::operator+(const Matrix& rhv) const {
    if (getSize() != rhv.getSize()) {
        throw std::invalid_argument("Matrix sizes are incompatible");
    }
    Matrix res(getSize().first, getSize().second, 0.0);
    for (size_t i = 0; i < getSize().first; ++i) {
        for (size_t j = 0; j < getSize().second; ++j) {
            res[i][j] = getEl(i, j) + rhv.getEl(i, j);
        }
    }
    return res;
}

Matrix operator*(const Matrix& lhv, double rhv) {
    Matrix resMat(lhv);
    for (size_t i = 0; i < resMat.getSize().first; ++i) {
        for (size_t j = 0; j < resMat.getSize().second; ++j) {
            resMat[i][j] *= rhv;
        }
    }
    return resMat;
}

Matrix operator*(double lhv, const Matrix& rhv) {
    return rhv * lhv;
}

int main() {
    return 0;
}