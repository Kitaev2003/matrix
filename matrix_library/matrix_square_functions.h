#ifndef MATRIX_SQUARE_FUNCTIONS_H
#define MATRIX_SQUARE_FUNCTIONS_H
#include "matrix.h"

template <class Type>
matrix_square<Type>::matrix_square(const unsigned int in_size) : size(in_size) {
  assert(size != 0 && "A matrix of one element does not make sense");

  matrix_square<Type>::height = size;
  matrix_square<Type>::width = size;

  matrix_square<Type>::data = new Type *[size];
  for (std::size_t i = 0; i != size; ++i)
    matrix_square<Type>::data[i] = new Type[size];
}

template <class Type>
matrix_square<Type>::matrix_square(matrix_square<Type> &rhs) {
  size = rhs.size;
  assert(rhs.size != 0 && "A matrix of one element does not make sense");
  matrix_square<Type>::height = size;
  matrix_square<Type>::width = size;

  matrix_square<Type>::data = new Type *[size];
  for (std::size_t i = 0; i != size; ++i)
    matrix_square<Type>::data[i] = new Type[size];

  for (std::size_t i = 0; i != size; ++i)
    for (std::size_t j = 0; j != size; ++j)
      matrix_square<Type>::data[i][j] = rhs.data[i][j];
}

template <class Type>
matrix_square<Type>::matrix_square(const unsigned int n, const unsigned int m) {
  assert(n == m && "The height and width of the matrix must be equal");
  matrix_square<Type>::height = n;
  matrix_square<Type>::width = m;
  size = n != 0 ? n : m;

  assert(size != 0 && "A matrix of one element does not make sense");

  matrix_square<Type>::data = new Type *[size];
  for (std::size_t i = 0; i != size; ++i)
    matrix_square<Type>::data[i] = new Type[size];
}

template <class Type> matrix_square<Type>::~matrix_square() {
  for (std::size_t i = 0; i != size; ++i)
    delete[] matrix_square<Type>::data[i];
  delete[] matrix_square<Type>::data;
}

template <class Type> bool matrix_square<Type>::isSquareType() { return true; }

template <class Type> unsigned int matrix_square<Type>::getSize() {
  return size;
}

template <class Type> Type matrix_square<Type>::tr() {
  Type trace = 0;

  for (auto itRow = matrix_square<Type>::begin();
       itRow != matrix_square<Type>::end(); ++itRow)
    for (auto itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      trace += *itCol;
  return trace;
}

template <class Type> Type matrix_square<Type>::det() {
  matrix_square R = *this;
  Type deter = 1;

  std::size_t qua = 1;
  std::size_t sign = 0;

  for (std::size_t c = 0; c < R.size; ++c) {
    while (fabs(R.data[c][c]) < __EPS__ && (c + qua) < R.size) {
      std::swap(R.data[c + qua], R.data[c]);
      qua++;
      sign++;
    }
    qua = 1;
  }

  std::size_t k = 0;

  Type val1, val2;
  while (k < (R.size - 1)) {
    for (std::size_t i = k; i < (R.size - 1); ++i) {
      if (fabs(R.data[k][k]) < __EPS__)
        return 0;

      val1 = R.data[k][k];
      if (fabs(R.data[i + 1][k]) < __EPS__)
        continue;

      val2 = R.data[i + 1][k];
      for (size_t j = 0; j < R.size; ++j)
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
    }
    deter *= R.data[k][k];
    k++;
  }
  std::cout << R << std::endl;
  deter *= R.data[k][k];

  if (fabs(deter) < __EPS__)
    return 0;

  return deter * std::pow(-1, sign);
}

template <class Type> inline void matrix_square<Type>::setUnit() {
  for (std::size_t i = 0; i != size; ++i)
    this->data[i][i] = __EQ__;
}

template <class Type>
inline void matrix_square<Type>::setMainDiag(const Type &Val) {
  for (std::size_t i = 0; i != size; ++i)
    this->data[i][i] = Val;
}

template <class Type> matrix_square<Type> matrix_square<Type>::inverse() {
  matrix_square R = *this;
  matrix_square<Type> E(size);

  E.setUnit();
  std::size_t qua = 1;
  std::size_t sign = 0;

  for (std::size_t c = 0; c < R.size; ++c) {
    while (fabs(R.data[c][c]) < __EPS__ && (c + qua) < R.size) {
      std::swap(R.data[c + qua], R.data[c]);
      std::swap(E.data[c + qua], E.data[c]);

      qua++;
      sign++;
    }
    qua = 1;
  }

  std::size_t k = 0;

  Type val1, val2;
  while (k < (R.size - 1)) {
    for (std::size_t i = k; i < (R.size - 1); ++i) {

      val1 = R.data[k][k];
      if (fabs(R.data[i + 1][k]) < __EPS__)
        continue;

      val2 = R.data[i + 1][k];
      for (size_t j = 0; j < R.size; ++j) {
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
        E.data[i + 1][j] = E.data[i + 1][j] - E.data[k][j] * (val2 / val1);
      }
    }
    k += 1;
  }

  std::cout << E << std::endl;
  std::cout << R << std::endl;

  while (k < (R.size - 1)) {
    for (std::size_t i = k; i < (R.size - 1); ++i) {
      val2 = R.data[i + 1][k];
      for (size_t j = 0; j < R.size; ++j) {
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
        E.data[i + 1][j] = E.data[i + 1][j] - E.data[k][j] * (val2 / val1);
      }
    }
    k -= 1;
  }

  std::cout << E << std::endl;
  std::cout << R << std::endl;

  return E;
}
#endif // MATRIX_SQUARE_FUNCTIONS_H