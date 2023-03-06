#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> 
#include <assert.h>

#define eps  0.0001

typedef std::vector<double> line;
typedef std::vector<line> table;
typedef line::iterator col;
typedef table::iterator row;

class matrix{
    friend const std::ostream& operator << (const std::ostream& os, const matrix& A);
    friend const std::istream& operator >> (const std::istream& is, matrix& A);
    friend matrix operator * (matrix& A, matrix& B);
    friend matrix operator + (matrix& A, matrix& B);
    friend matrix operator - (matrix& A, matrix& B);
    friend matrix operator * (double val, matrix& A);

    template <typename T>
    friend  matrix fscan(T& det);//for testing
private:
    size_t width;
    size_t height;

    table data; 
public:
    matrix(const size_t n, const size_t m);
    ~matrix();

    void scan();
    void print();
    double det();
    double tr();
    size_t rang();
};

#endif//MATRIX_H