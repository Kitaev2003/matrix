#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H
#include "matrix.h"

template <class Type>
matrix<Type>::matrix(const unsigned int n, const unsigned int m)
    : width(m), height(n) {
  data.resize(height);
  for (auto &col : data)
    col.resize(width);
}

template <class Type>
matrix<Type>::matrix(const matrix &rhs) {
  height = rhs.height;
  width = rhs.width;
  data = rhs.data;
}

template <class Type>
matrix<Type>::~matrix() {}

template <class Type>
std::istream &matrix<Type>::scan(std::istream &is) {
  for (Row itRow = begin(); itRow != end(); ++itRow)
    for (Col itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      is >> *itCol;
  return is;
}

template <class Type>
std::ostream &matrix<Type>::print(std::ostream &os) {
  os << "Height:" << height << "\nWidth:" << width << std::endl;

  for (Row itRow = begin(); itRow != end(); ++itRow) {
    for (Col itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      os << *itCol << " ";
    os << std::endl;
  }
  return os;
}


template <class Type>
unsigned int matrix<Type>::rang() {
  matrix R = *this;

  std::size_t qua = 1;
  for (std::size_t c = 0; c < R.height; ++c) {
    while (fabs(R.data[c][c]) < eps && (c + qua) < height) {
      std::swap(R.data[c], R.data[c + qua]);
      qua++;
    }
    qua = 1;
  }

  Type val1, val2;
  for (std::size_t k = 0; k < (R.height - 1); ++k) {
    for (std::size_t i = k; i < (R.height - 1); ++i) {
      if (fabs(R.data[k][k]) < eps || fabs(R.data[i + 1][k]) < eps)
        continue;

      val1 = R.data[k][k];
      val2 = R.data[i + 1][k];

      for (std::size_t j = 0; j < R.width; ++j)
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
    }
  }

  size_t k = 0;
  unsigned int rg = 0;

  for (std::size_t i = 0; i < R.height; ++i) 
    for (std::size_t j = k; j < R.width; ++j) {
      if (R.data[i][j] > eps) {
        rg++;
        k = j + 1;
        break;
      }
    }
  return rg;
}

template <class Type>
void matrix<Type>::trans() {
  matrix A(width, height);
  for (std::size_t i = 0; i < height; ++i) 
    for (std::size_t j = 0; j < width; ++j) {
      if (i != j) {
        A.data[j][i] = data[i][j];
        A.data[i][j] = data[j][i];
      }
    }
  *this = A;
}
#endif // MATRIX_FUNCTIONS_H
