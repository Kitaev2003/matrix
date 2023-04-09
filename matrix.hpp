#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>

#define eps  0.000001

    typedef std::vector<double> line;       //container
    typedef std::vector<line>  table;       //container

    typedef line::iterator  Col_Iterator;   //iterator
    typedef table::iterator row;            //iterator

class RowIterator: public std::iterator<std::input_iterator_tag, Col_Iterator>{
    friend class matrix;
private:
    row p;
    RowIterator(row p_);
public:
    RowIterator(const RowIterator &it);
    RowIterator& operator=(RowIterator const& rhs);

    bool operator!=(RowIterator const& rhs) const;
    RowIterator& operator++();

    Col_Iterator begin();
    Col_Iterator end();
};


class matrix{
    friend std::ostream& operator << (std::ostream& os, const matrix& A);
    friend std::istream& operator >> (std::istream& is, matrix& A);
protected:
    unsigned int width;
    unsigned int height;
    
    table data;
public:
    matrix() = default;
    matrix(const unsigned int n, const unsigned int m);
    matrix(matrix& rhs);
    virtual ~matrix();

    matrix& operator= (matrix& rhs);
    matrix operator * (matrix& B);
    matrix operator  * (double val);
    matrix& operator += (matrix& B);
    matrix& operator -= (matrix& B);

    RowIterator begin();
    RowIterator end();

    void scan();
    void print();
    void trans();
    unsigned int rang();

};
matrix operator -  (matrix& A, matrix& B);
matrix operator +  (matrix& A, matrix& B);

class matrix_square : public matrix{
private:
    unsigned int size;
public:
    matrix_square() = default;
    matrix_square(const unsigned int in_size);
    matrix_square(const unsigned int n, const unsigned int m);
    ~matrix_square() override;

    matrix_square& operator *= (matrix_square &B);

    double det();
    double tr();
};
matrix_square operator* (matrix_square& A, matrix_square &B);
#endif //MATRIX_H
