// Declaration part of a module for the Matrix class.
#ifndef MATRIX_H
#define MATRIX_H


// TODO: provide a declaration of the class Matrix as it prescribed in the task.
#include <vector>

class Matrix {
public:
    typedef std::vector<double> MatrixVector;
    typedef std::vector<MatrixVector> VectorOfMatrixVector;
    typedef std::pair<size_t, size_t> SizePair;

    static MatrixVector Matrix::createVector(size_t sz, double val);

    Matrix(size_t m, size_t n, double def);
    Matrix() : Matrix(0, 0, 0.0) {}

    void resize(size_t m, size_t n, double def);

    SizePair Matrix::getSize() const;

    MatrixVector& operator[](const size_t i);
    const MatrixVector& operator[](const size_t i) const;

    double Matrix::getEl(size_t i, size_t j) const;
    void Matrix::setEl(size_t i, size_t j, double val);

private:
    VectorOfMatrixVector _matrix;
};

#endif // MATRIX_H
