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

protected:
    unsigned int width;
    unsigned int height;

    table data; 
public:
    virtual matrix operator * ( matrix& B);
    matrix operator * (double val);
    matrix& operator += (matrix& B);
    matrix& operator -= (matrix& B);

    matrix() = default;
    matrix(const unsigned int n, const unsigned int m);
    virtual ~matrix();

    void scan();
    void print();
    unsigned int rang();
};
matrix operator -  (matrix& A, matrix& B);
matrix operator +  (matrix& A, matrix& B);


class matrix_square : public matrix{
private:
    unsigned int size;
public:
    matrix_square(const unsigned int in_size);
    ~matrix_square();

    matrix_square& operator *= (matrix_square &B);

    double det();
    double tr();
};
matrix_square operator* (matrix_square& A, matrix_square &B);

#endif //MATRIX_H