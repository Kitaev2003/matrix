#ifndef MATRIX_OPERATORS_H
#define MATRIX_OPERATORS_H

template <class Type> 
matrix<Type> &matrix<Type>::operator=(matrix<Type> &rhs) {
  width = rhs.width;
  height = rhs.height;

  data = rhs.data;

  return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &A) { // friend
  os << "Height:" << A.height << "\nWidth:" << A.width << std::endl;

  for (size_t i = 0; i < A.width; ++i) {
    for (size_t j = 0; j < A.width; ++j) {
      os << A.data[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, matrix<T> &A) { // friend
  Type val;
  for (size_t i = 0; i < A.height; ++i) {
    for (size_t j = 0; j < A.width; ++j) {
      is >> val;
      A.data[i][j] = val;
    }
  }
  return is;
}

template <class Type>
matrix<Type> matrix<Type>::operator*(matrix<Type> &B) { // friend
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
matrix<Type> matrix<Type>::operator*(Type val) { // friend
  matrix C = *this;
template <class Type>
  for (size_t i = 0; i < this->height; ++i) {
    for (size_t j = 0; j < this->width; ++j) {
      C.data[i][j] *= val;
    }
  }
  return C;
}

template <class Type> 
matrix<Type> &matrix<Type>::operator+=(matrix<Type> &B) {
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
matrix<Type> &matrix<Type>::operator-=(matrix<Type> &B) {
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
#endif //MATRIX_OPERATORS_H