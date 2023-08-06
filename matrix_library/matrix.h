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
public:
  class RowIterator;
  RowIterator begin();
  RowIterator end();

protected:
  unsigned int width;
  unsigned int height;
  std::vector<std::vector<Type>> data;

  typedef RowIterator Row;
  typedef typename RowIterator::ColIterator Col;
public:
  matrix(const unsigned int n, const unsigned int m);
  matrix(const matrix<Type> &rhs);
  matrix() = default;
  virtual ~matrix();

  const std::vector<Type> &operator[](const std::size_t num) const;
  matrix<Type> &operator=(const matrix<Type> &rhs);
  matrix<Type> &operator+=(const matrix<Type> &rhs);
  matrix<Type> &operator-=(const matrix<Type> &rhs);
  matrix<Type> operator*(const matrix<Type> &rhs) const;
  matrix<Type> operator*(const Type val) const;
  bool operator==(const matrix<Type> &rhs) const;
  bool operator!=(const matrix<Type> &rhs) const;

  std::istream &scan(std::istream &is);
  std::ostream &print(std::ostream &os);
  void trans();
  unsigned int rang();
};

template <class Type>
std::ostream &operator<<(std::ostream &os, matrix<Type> &A);
template <class Type>
std::istream &operator>>(std::istream &is, matrix<Type> &A);
template <class Type>
matrix<Type> operator+(const matrix<Type> &lhs, const matrix<Type> &rhs);
template <class Type>
matrix<Type> operator-(const matrix<Type> &lhs, const matrix<Type> &rhs);

// Matrx_square class
template <class Type> 
class matrix_square : public matrix<Type> {
protected:
  unsigned int size;
public:
  matrix_square() = default;
  matrix_square(const unsigned int in_size);
  matrix_square(const unsigned int n, const unsigned int m);
  ~matrix_square() override;

  matrix_square<Type> &operator*=(const matrix_square<Type> &rhs);

  Type det();
  Type tr();
};
template <class Type>
matrix_square<Type> operator*(const matrix_square<Type> &lhs,
                              const matrix_square<Type> &rhs);

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

#ifdef TESTING
template <class Type> matrix<Type> filescan(Type& det);
template <class Type> matrix_square<Type> filescan_S(Type& det);
#endif

#endif // MATRIX_H
