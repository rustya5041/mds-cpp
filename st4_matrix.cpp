// Implementation part of a module for the Matrix class.
#include "matrix.h"

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