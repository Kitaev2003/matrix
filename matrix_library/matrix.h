#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#ifndef MATRIX_H
#define MATRIX_H

#define __EPS__ 0.000001
#define __EQ__ 1

template <class Type> class matrix;
template <class Type> class matrix_square;
template <class Type> class RowIterator;
template <class Type> class ColIterator;

/// Matrix class
template <class Type> class matrix {
public:
  typedef RowIterator<Type> Riterator;

  typedef const RowIterator<Type> const_Riterator;

  Riterator begin();

  Riterator end();

  const_Riterator begin() const;

  const_Riterator end() const;

protected:
  unsigned int width;

  unsigned int height;

  Type **data;

public:
  matrix(const unsigned int n, const unsigned int m);

  matrix(const matrix<Type> &rhs);

  matrix() = default;

  virtual ~matrix();

  unsigned int getWidth();

  unsigned int getHeight();

  bool isSquare();

  virtual bool isSquareType();

  const Type *operator[](const std::size_t num) const;

  matrix<Type> &operator=(const matrix<Type> &rhs);

  matrix<Type> &operator+=(const matrix<Type> &rhs);

  matrix<Type> &operator-=(const matrix<Type> &rhs);

  matrix<Type> operator*(const matrix<Type> &rhs) const;

  matrix<Type> operator*(const Type val) const;

  bool operator==(const matrix<Type> &rhs) const;

  bool operator!=(const matrix<Type> &rhs) const;

  std::istream &scan(std::istream &is);

  std::ostream &print(std::ostream &os) const;

  void set(Type element);

  bool empty() const;

  void insert(typename Riterator::const_Citerator block, Type &element);

  void insert(unsigned int Row, unsigned int Col, Type &element);

  std::pair<const_Riterator, typename const_Riterator::const_Citerator>
  find(Type element) const;

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

/// Matrx_square class
template <class Type> class matrix_square final : public matrix<Type> {
private:
  unsigned int size;

public:
  matrix_square() = default;

  matrix_square(matrix_square<Type> &rhs);

  matrix_square(const unsigned int in_size);

  matrix_square(const unsigned int n, const unsigned int m);

  ~matrix_square() override;

  matrix_square<Type> &operator=(const matrix_square<Type> &rhs);

  matrix_square<Type> &operator*=(const matrix_square<Type> &rhs);

  bool isSquareType() override;

  unsigned int getSize();

  Type det();

  Type tr();

  inline void setUnit();

  inline void setMainDiag(const Type &Val);

  matrix_square inverse();
};
template <class Type>
matrix_square<Type> operator*(const matrix_square<Type> &lhs,
                              const matrix_square<Type> &rhs);

/// RowIterator class
template <class Type>
class RowIterator final : public std::iterator<std::input_iterator_tag, Type> {
  friend class matrix<Type>;

private:
  Type **Point;

  unsigned int width;

public:
  RowIterator() = default;

  ~RowIterator() = default;

  RowIterator(Type **Point_, unsigned int width_);

  RowIterator(const RowIterator<Type> &rhs);

  RowIterator<Type> &operator=(const RowIterator<Type> &rhs);

  typename RowIterator::reference operator*() const;

  bool operator!=(RowIterator<Type> const &rhs) const;

  bool operator==(RowIterator<Type> const &rhs) const;

  RowIterator<Type> &operator++();

  typedef ColIterator<Type> Citerator;

  typedef const ColIterator<Type> const_Citerator;

  Citerator begin();

  Citerator end();

  const_Citerator begin() const;

  const_Citerator end() const;
};

/// ColIterator class
template <class Type>
class ColIterator final : public std::iterator<std::input_iterator_tag, Type> {
  friend class matrix<Type>;

private:
  Type *Point;

public:
  ColIterator() = default;

  ~ColIterator() = default;

  ColIterator(Type *Point_);

  ColIterator(const ColIterator<Type> &rhs);

  ColIterator &operator=(const ColIterator<Type> &rhs);

  typename ColIterator::reference &operator*() const;

  bool operator!=(ColIterator<Type> const &rhs) const;

  bool operator==(ColIterator<Type> const &rhs) const;

  ColIterator<Type> &operator++();
};

#ifdef __TESTING__
template <class Type> matrix<Type> filescan(Type &det);

template <class Type> matrix_square<Type> filescan_S(Type &det);
#endif // TESTING

#endif // MATRIX_H
