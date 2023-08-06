#ifndef MATRIX_SQUARE_FUNCTIONS_H
#define MATRIX_SQUARE_FUNCTIONS_H
#include "matrix.h"

template <class Type>
matrix_square<Type>::matrix_square(const unsigned int in_size) : size(in_size) {
  matrix_square<Type>::height = size;
  matrix_square<Type>::width = size;
  matrix_square<Type>::data.resize(size);
  for (auto &col : matrix_square<Type>::data)
    col.resize(matrix_square<Type>::width);
}

template <class Type>
matrix_square<Type>::matrix_square(const unsigned int n, const unsigned int m) {
  assert(n == m);
  matrix_square<Type>::height = n;
  matrix_square<Type>::width = m;
  size = n;

  matrix_square<Type>::data.resize(size);
  for (auto &col : matrix_square<Type>::data)
    col.resize(matrix_square<Type>::width);
}

template <class Type> 
matrix_square<Type>::~matrix_square() {}

template <class Type> 
Type matrix_square<Type>::tr() {
  Type trace = 0;

  for (typename matrix_square<Type>::Row itRow = matrix_square<Type>::begin(); itRow != matrix_square<Type>::end(); ++itRow)
    for (typename matrix_square<Type>::Col itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      trace += *itCol;
  return trace;
}

template <class Type> 
Type matrix_square<Type>::det() {
  matrix_square R = *this;
  Type deter = 1;

  std::size_t qua = 1;
  std::size_t sign = 0;

  for (std::size_t c = 0; c < R.size; ++c) {
    while (fabs(R.data[c][c]) < eps && (c + qua) < R.size) {
      std::swap(R.data[c + qua], R.data[c]);
      qua++;
      sign++;
    }
    qua = 1;
  }

  std::size_t k = 0;

  Type val1, val2;
  while (k < (R.size - 1)) {
    for(std::size_t i = k; i < (R.size - 1); ++i) {
      if (fabs(R.data[k][k]) < eps)
        return 0;

      val1 = R.data[k][k];
      if (fabs(R.data[i + 1][k]) < eps)
        continue;

      val2 = R.data[i + 1][k];
      for (size_t j = 0; j < R.size; ++j)
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
    }
    deter *= R.data[k][k];
    k++;
  }
  deter *= R.data[k][k];

  if (fabs(deter) < eps)
    return 0;

  return deter * std::pow(-1, sign);
}
#endif //MATRIX_SQUARE_FUNCTIONS_H