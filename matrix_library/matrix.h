#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define eps  0.000001

//Matrix class
template <class Type> 
class matrix{
    template <typename T>
    friend std::ostream& operator << (std::ostream& os, const matrix<T> &A);
    template <typename T>
    friend std::istream& operator >> (std::istream& is, matrix<T> &A);
protected:
    unsigned int width;
    unsigned int height;

    std::vector<std::vector<Type>> data;
public:
    class RowIterator;
    matrix(const unsigned int n, const unsigned int m);
    matrix(matrix<Type>& rhs);
    matrix() = default;
    virtual ~matrix();

    matrix<Type>& operator  = (matrix<Type> const& rhs);
    matrix<Type>& operator += (matrix<Type> const& B);
    matrix<Type>& operator -= (matrix<Type> const& B);
    matrix<Type> operator * (matrix<Type> const& B);
    matrix<Type> operator * (const Type val);

    RowIterator begin();//
    RowIterator end();//

    void scan();
    void print();
    void trans();
    unsigned int rang();
};
template <class Type>
matrix<Type> operator +  (matrix<Type>& A, matrix<Type>& B);
template <class Type>
matrix<Type> operator -  (matrix<Type>& A, matrix<Type>& B);

//Matrx_square class
template <class Type>
class matrix_square : public matrix<Type> {
private:
    unsigned int size;
public:
    matrix_square() = default;
    matrix_square(const unsigned int in_size);
    matrix_square(const unsigned int n, const unsigned int m);
    ~matrix_square() override;

    matrix_square& operator *= (matrix_square &B);

    Type det();
    Type tr();
};
template <class Type>
matrix_square<Type> operator* (matrix_square<Type>& A, matrix_square<Type> &B);

template <class Type>
class matrix<Type>::RowIterator {
private:
    typename std::vector<std::vector<Type>>::iterator iter;
public:
    class ColIterator; 
    RowIterator(){};
    ~RowIterator() = default;
    RowIterator& operator=(RowIterator const& rhs);
    bool operator != (RowIterator const& rhs);
    bool operator == (RowIterator const& rhs);

    RowIterator& operator++();

    ColIterator begin();
    ColIterator end();
};

#endif //MATRIX_H
