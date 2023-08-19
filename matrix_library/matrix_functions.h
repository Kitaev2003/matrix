#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H
#include "matrix.h"

template <class Type>
matrix<Type>::matrix(const unsigned int n, const unsigned int m)
    : width(m), height(n) {
  assert((width != 0 || height != 0) &&
         "A matrix of one element does not make sense");
  data = new Type *[height];
  for (std::size_t i = 0; i != height; ++i)
    data[i] = new Type[width];
}

template <class Type> matrix<Type>::matrix(const matrix &rhs) {
  height = rhs.height;
  width = rhs.width;
  assert((width != 0 || height != 0) &&
         "A matrix of one element does not make sense");

  data = new Type *[height];
  for (std::size_t i = 0; i != height; ++i)
    data[i] = new Type[width];

  for (std::size_t i = 0; i != height; ++i)
    for (std::size_t j = 0; j != width; ++j)
      data[i][j] = rhs.data[i][j];
}

template <class Type> matrix<Type>::~matrix() {
  for (std::size_t i = 0; i != height; ++i)
    delete[] data[i];
  delete[] data;
}

template <class Type> unsigned int matrix<Type>::getHeight() { return height; }

template <class Type> unsigned int matrix<Type>::getWidth() { return width; }

template <class Type> bool matrix<Type>::isSquare() { return width == height; }

template <class Type> bool matrix<Type>::isSquareType() { return false; }

template <class Type> void matrix<Type>::set(Type element) {
  for (auto itRow = begin(); itRow != end(); ++itRow)
    for (auto itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      *itCol = element;
}

template <class Type> bool matrix<Type>::empty() const {
  if (height == 0 || width == 0)
    return true;
  for (auto itRow = begin(); itRow != end(); ++itRow)
    for (auto itCol = itRow.begin(); itCol != itRow.end(); ++itCol) {
      if (fabs(*itCol) > __EPS__)
        return false;
    }
  return false;
}

template <class Type>
std::pair<typename matrix<Type>::const_Riterator,
          typename matrix<Type>::const_Riterator::const_Citerator>
matrix<Type>::find(Type element) const {
  for (auto itRow = begin(); itRow != end(); ++itRow)
    for (auto itCol = itRow.begin(); itCol != itRow.end(); ++itCol) {
      if (*itCol == element)
        return std::make_pair(itRow, itCol);
    }
  return std::make_pair(this->end(), this->end().end());
}

template <class Type>
void matrix<Type>::insert(
    typename matrix<Type>::Riterator::const_Citerator block, Type &element) {
  *(block.second) = element;
}

template <class Type>
void matrix<Type>::insert(unsigned int Row, unsigned int Col, Type &element) {
  data[Row][Col] = element;
}

template <class Type> std::istream &matrix<Type>::scan(std::istream &is) {
  for (auto itRow = begin(); itRow != end(); ++itRow)
    for (auto itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      is >> *itCol;
  return is;
}

template <class Type>
std::ostream &matrix<Type>::print(std::ostream &os) const {
  os << "Height:" << height << "\nWidth:" << width << std::endl;

  for (auto itRow = begin(); itRow != end(); ++itRow) {
    for (auto itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      os << *itCol << " ";
    os << std::endl;
  }
  return os;
}

template <class Type> unsigned int matrix<Type>::rang() {
  matrix R = *this;

  std::size_t qua = 1;
  for (std::size_t c = 0; c < R.height; ++c) {
    while (fabs(R.data[c][c]) < __EPS__ && (c + qua) < height) {
      std::swap(R.data[c], R.data[c + qua]);
      qua++;
    }
    qua = 1;
  }

  Type val1, val2;
  for (std::size_t k = 0; k < (R.height - 1); ++k) {
    for (std::size_t i = k; i < (R.height - 1); ++i) {
      if (fabs(R.data[k][k]) < __EPS__ || fabs(R.data[i + 1][k]) < __EPS__)
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
      if (R.data[i][j] > __EPS__) {
        rg++;
        k = j + 1;
        break;
      }
    }
  return rg;
}

template <class Type> void matrix<Type>::trans() {
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
