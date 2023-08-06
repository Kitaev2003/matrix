#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define eps 0.000001

// Matrix class
template <class Type>
class matrix {
  template <typename T>
  friend std::ostream &operator<<(std::ostream &os, const matrix<T> &A);
  template <typename T>
  friend std::istream &operator>>(std::istream &is, matrix<T> &A);

protected:
  unsigned int width;
  unsigned int height;
  std::vector<std::vector<Type>> data;

public:
  class RowIterator;
  RowIterator begin();
  RowIterator end();

protected:
  typedef RowIterator Row;
  typedef typename RowIterator::ColIterator Col;
  
public:
  matrix(const unsigned int n, const unsigned int m);
  matrix(matrix<Type> &rhs);
  matrix() = default;
  virtual ~matrix();

  matrix<Type> &operator=(matrix<Type> const &rhs);
  matrix<Type> &operator+=(matrix<Type> const &B);
  matrix<Type> &operator-=(matrix<Type> const &B);
  matrix<Type> operator*(matrix<Type> const &B);
  matrix<Type> operator*(const Type val);

  void scan();
  void print();
  void trans();
  unsigned int rang();
};
template <class Type> 
matrix<Type> operator+(matrix<Type> &A, matrix<Type> &B);
template <class Type> 
matrix<Type> operator-(matrix<Type> &A, matrix<Type> &B);

// Matrx_square class
template <class Type> 
class matrix_square : public matrix<Type> {
private:
  unsigned int size;

public:
  matrix_square() = default;
  matrix_square(const unsigned int in_size);
  matrix_square(const unsigned int n, const unsigned int m);
  ~matrix_square() override;

  matrix_square &operator*=(matrix_square &B);

  Type det();
  Type tr();
};
template <class Type>
matrix_square<Type> operator*(matrix_square<Type> &A, matrix_square<Type> &B);

template <class Type>
class matrix<Type>::RowIterator
    : public std::iterator<std::input_iterator_tag, Type> {
  friend class matrix<Type>;

private:
  typename std::vector<std::vector<Type>>::iterator iter;

public:
  RowIterator() = default;
  ~RowIterator() = default;
  RowIterator(const RowIterator &rhs);
  RowIterator &operator=(const RowIterator &rhs);
  RowIterator(const typename std::vector<std::vector<Type>>::iterator &rhs);

  std::vector<Type> &operator*() const;
  bool operator!=(RowIterator const &rhs) const;
  bool operator==(RowIterator const &rhs) const;
  RowIterator &operator++();

  class ColIterator;
  ColIterator begin();
  ColIterator end();
};

template <class Type>
class matrix<Type>::RowIterator::ColIterator
    : public std::iterator<std::input_iterator_tag, Type> {
  friend class matrix<Type>;

private:
  typename std::vector<Type>::iterator iter;

public:
  ColIterator() = default;
  ~ColIterator() = default;
  ColIterator(const ColIterator &rhs);
  ColIterator &operator=(const ColIterator &rhs);
  ColIterator(const typename std::vector<Type>::iterator &rhs);

  Type &operator*() const;
  bool operator!=(ColIterator const &rhs) const;
  bool operator==(ColIterator const &rhs) const;
  ColIterator &operator++();
};
#endif // MATRIX_H
