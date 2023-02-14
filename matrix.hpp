#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <cmath> 
#include <assert.h>

const double eps = 0.0001;

typedef std::vector<double> line;
typedef std::vector<line> table;
typedef line::iterator col;
typedef table::iterator row;


class matrix{

    friend const std::ostream& operator << (const std::ostream& os, const matrix& A);
    friend const std::istream& operator >> (const std::istream &is, const matrix& A);
    friend matrix operator * (matrix &A, matrix &B);
    friend matrix operator + (matrix &A, matrix &B);
private:
    size_t width;
    size_t height;

    table data; 
public:
    matrix(const size_t n, const size_t m);
    ~matrix();

    void scan();
    void print();
    double det(matrix A);
    size_t rang(matrix A);
};