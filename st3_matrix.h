// Declaration part of a module for the Matrix class.
#ifndef MATRIX_H
#define MATRIX_H


// TODO: provide a declaration of the class Matrix as it prescribed in the task.
#include <vector>

class Matrix {
public:
    typedef std::vector<double> MatrixVector;
    typedef std::vector<MatrixVector> VectorOfMatrixVector;

    static MatrixVector Matrix::createVector(size_t sz, double val);

    Matrix(size_t m, size_t n, double def);
    Matrix() : Matrix(0, 0, 0.0) {}

    void resize(size_t m, size_t n, double def);
    
private:
    VectorOfMatrixVector _matrix;
};

#endif // MATRIX_H
