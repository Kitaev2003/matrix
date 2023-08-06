#ifndef MATRIX_OPERATORS_H
#define MATRIX_OPERATORS_H
#include "matrix.h"

template <class Type>
matrix<Type> &matrix<Type>::operator=(const matrix<Type> &rhs) {
  width = rhs.width;
  height = rhs.height;
  data = rhs.data;

  return *this;
}

template <class Type>
std::istream &operator>>(std::istream &is, matrix<Type> &A) {
  return A.scan(is);
}

template <class Type>
std::ostream &operator<<(std::ostream &os, matrix<Type> &A) {
  return A.print(os);
}

template <class Type>
const std::vector<Type> &matrix<Type>::operator[](const std::size_t num) const {
  return data[num];
}

template <class Type>
matrix<Type> matrix<Type>::operator*(const Type val) const { // friend
  matrix C(*this);
  for (Row itRow = C.begin(); itRow != C.end(); ++itRow)
    for (Col itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      *itCol *= val;
  return C;
}

template <class Type>
matrix<Type> &matrix<Type>::operator+=(const matrix<Type> &rhs) {
  assert(width == rhs.width);
  assert(height == rhs.height);

  for (std::size_t i = 0; i < height; ++i)
    for (std::size_t j = 0; j < width; ++j)
      data[i][j] = data[i][j] + rhs.data[i][j];
  return *this;
}

template <class Type>
matrix<Type> &matrix<Type>::operator-=(const matrix<Type> &rhs) {
  assert(width == rhs.width);
  assert(height == rhs.height);

  for (std::size_t i = 0; i < height; ++i)
    for (std::size_t j = 0; j < width; ++j)
      this->data[i][j] = data[i][j] - rhs.data[i][j];
  return *this;
}

template <class Type>
matrix<Type> matrix<Type>::operator*(const matrix<Type> &rhs) const {
  assert(width == rhs.height);
  matrix C(height, rhs.width);
  std::cout << C[1][1];
  for (std::size_t ic = 0; ic < C.height; ++ic)
    for (std::size_t jc = 0; jc < C.width; ++jc)
      for (std::size_t k = 0; k < width; ++k)
        C.data[ic][jc] += data[ic][k] * rhs.data[k][jc];
  return C;
}

template <class Type>
matrix<Type> operator+(const matrix<Type> &lhs, const matrix<Type> &rhs) {
  matrix<Type> C = lhs;
  C += rhs;
  return C;
}

template <class Type>
matrix<Type> operator-(const matrix<Type> &lhs, const matrix<Type> &rhs) {
  matrix<Type> C = lhs;
  C -= rhs;
  return C;
}

template <class Type>
bool matrix<Type>::operator!=(const matrix<Type> &rhs) const {
  if (width != rhs.width || height != rhs.height)
    return true;
  for (std::size_t i = 0; i != height; ++i)
    for (std::size_t j = 0; j != width; ++j)
      if (data[i][j] != rhs.data[i][j])
        return true;
  return false;
}

template <class Type>
bool matrix<Type>::operator==(const matrix<Type> &rhs) const {
  if (width != rhs.width || height != rhs.height)
    return false;
  for (std::size_t i = 0; i != height; ++i)
    for (std::size_t j = 0; j != width; ++j)
      if (data[i][j] != rhs.data[i][j])
        return false;
  return true;
}

template <class Type>
matrix_square<Type> &
matrix_square<Type>::operator*=(const matrix_square<Type> &rhs) {
  assert(size == rhs.size);
  matrix_square<Type> C(size);

  for (std::size_t ic = 0; ic < C.size; ++ic)
    for (std::size_t jc = 0; jc < C.size; ++jc)
      for (std::size_t k = 0; k < C.size; ++k)
        C.data[ic][jc] += this->data[ic][k] * rhs.data[k][jc];
  *this = C;
  return *this;
}

template <class Type>
matrix_square<Type> operator*(const matrix_square<Type> &lhs,
                              const matrix_square<Type> &rhs) {
  matrix_square<Type> C = lhs;
  C *= rhs;
  return C;
}

#endif // MATRIX_OPERATORS_H