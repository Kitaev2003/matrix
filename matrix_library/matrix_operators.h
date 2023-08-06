#ifndef MATRIX_OPERATORS_H
#define MATRIX_OPERATORS_H
#include "matrix.h"

template <class Type> 
matrix<Type> &matrix<Type>::operator=(matrix<Type> const &rhs) {
  width = rhs.width;
  height = rhs.height;
  data = rhs.data;

  return *this;
}

template <class Type>
std::ostream &operator<<(std::ostream &os, const matrix<Type> &A) { // friend
  os << "Height:" << A.height << "\nWidth:" << A.width << std::endl;

  for (Row itRow = begin(); itRow != end(); ++itRow) {
    for (Col itCol = itRow.begin(); itCol != itRow.end(); ++itCol)
      os << *itCol << " ";
    os << std::endl;
  }
  return os;
}


template <class Type>
std::istream &operator>>(std::istream &is, matrix<Type> &A) { // friend
  Type Val;
  for (Row itRow = begin(); itRow != end(); ++itRow) {
    for (Col itCol = itRow.begin(); itCol != itRow.end(); ++itCol){
      is >> Val;
      *itCol = Val;
    }
  }
  return is;
}
/*
template <class Type>
matrix<Type> matrix<Type>::operator*(matrix<Type> const &B) {
  assert(this->width == B.height);
  matrix C(this->height, B.width);

  for (size_t ic = 0; ic < C.height; ++ic) {
    for (size_t jc = 0; jc < C.width; ++jc) {
      for (size_t k = 0; k < this->width; ++k) {
        C.data[ic][jc] += this->data[ic][k] * B.data[k][jc];
      }
    }
  }
  return C;
}

template <class Type> 
matrix<Type> matrix<Type>::operator*(const Type val) { // friend
  matrix C = *this;
  for (size_t i = 0; i < this->height; ++i) {
    for (size_t j = 0; j < this->width; ++j) {
      C.data[i][j] *= val;
    }
  }
  return C;
}

template <class Type> 
matrix<Type> &matrix<Type>::operator+=(matrix<Type> const &B) {
  assert(this->width == B.width);
  assert(this->height == B.height);

  for (size_t i = 0; i < this->height; ++i) {
    for (size_t j = 0; j < this->width; ++j) {
      this->data[i][j] = this->data[i][j] + B.data[i][j];
    }
  }
  return *this;
}

template <class Type> 
matrix<Type> &matrix<Type>::operator-=(matrix<Type> const &B) {
  assert(this->width == B.width);
  assert(this->height == B.height);

  for (size_t i = 0; i < this->height; ++i) {
    for (size_t j = 0; j < this->width; ++j) {
      this->data[i][j] = this->data[i][j] - B.data[i][j];
    }
  }
  return *this;
}

template <class Type> 
matrix<Type> operator+(matrix<Type> &A, matrix<Type> &B) {
  matrix C = A;
  C += B;
  return C;
}

template <class Type> 
matrix<Type> operator-(matrix<Type> &A, matrix<Type> &B) {
  matrix C = A;
  C -= B;
  return C;
}

template <class Type>
matrix_square<Type> &matrix_square<Type>::operator*=(matrix_square<Type> &B) {
  assert(this->size == B.size);

  matrix_square C(this->size);

  for (size_t ic = 0; ic < C.size; ++ic) {
    for (size_t jc = 0; jc < C.size; ++jc) {
      for (size_t k = 0; k < C.size; ++k) {
        C.data[ic][jc] += this->data[ic][k] * B.data[k][jc];
      }
    }
  }
  *this = C;
  return *this;
}

template <class Type>
matrix_square<Type> operator*(matrix_square<Type> &A, matrix_square<Type> &B) {
  matrix_square C = A;
  C *= B;
  return C;
}
*/
#endif //MATRIX_OPERATORS_H