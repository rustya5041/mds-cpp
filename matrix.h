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

    static MatrixVector createVector(size_t sz, double val);

    Matrix(size_t m, size_t n, double def);
    Matrix(): Matrix(0, 0, 0.0) {}

    void resize(size_t m, size_t n, double def);

    SizePair getSize() const;

    MatrixVector& operator[](const size_t i);
    const MatrixVector& operator[](const size_t i) const;

    double getEl(size_t i, size_t j) const;
    void setEl(size_t i, size_t j, double val);

    bool operator == (const Matrix& rhv) const;
    bool operator != (const Matrix& rhv) const;

    Matrix operator + (const Matrix& rhv) const;
    
    friend Matrix operator * (const Matrix& lhv, double rhv);
    friend Matrix operator * (double lhv, const Matrix& rhv);

private:
    VectorOfMatrixVector _matrix;
};

Matrix operator * (const Matrix& lhv, double rhv);
Matrix operator * (double lhv, const Matrix& rhv);

#endif // MATRIX_H
