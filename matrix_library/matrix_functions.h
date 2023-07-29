#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H

template <class Type>
matrix<Type>::matrix(const unsigned int n, const unsigned int m)
    : width(m), height(n) {
  data.resize(height);

  for (RowIterator iter = data.begin(); iter < data.end(); ++iter) {
    iter->resize(width);
  }
}
template <class Type> matrix<Type>::matrix(matrix &rhs) {
  height = rhs.height;
  width = rhs.width;

  data = rhs.data;
}

template <class Type> 
matrix<Type>::~matrix() {
  for (RowIterator iter = data.begin(); iter < data.end(); ++iter) {
    iter->resize(0);
  }

  data.resize(0);
}

template <class Type>
void matrix<Type>::scan() {
  for (RowIterator i = data.begin(); i < data.end(); ++i) {
    for (ColIterator j = i->begin(); j < i->end(); ++j) {
      std::cin >> *j;
    }
  }
}

template <class Type> 
void matrix<Type>::print() {
  std::cout << "Height:" << height << "\nWidth:" << width << std::endl;

  for (RowIterator i = data.begin(); i < data.end(); ++i) {
    for (ColIterator j = i->begin(); j < i->end(); ++j) {
      std::cout << *j << " ";
    }
    std::cout << std::endl;
  }
}

template <class Type> 
unsigned int matrix<Type>::rang() {
  matrix R = *this;

  size_t qua = 1;
  for (size_t c = 0; c < R.height; ++c) {
    while (fabs(R.data[c][c]) < eps && (c + qua) < R.height) {
      std::swap(R.data[c], R.data[c + qua]);
      qua++;
    }
    qua = 1;
  }

  Type val1, val2;
  for (size_t k = 0; k < (R.height - 1); ++k) {
    for (size_t i = k; i < (R.height - 1); ++i) {
      if (fabs(R.data[k][k]) < eps || fabs(R.data[i + 1][k]) < eps) {
        continue;
      }
      val1 = R.data[k][k];
      val2 = R.data[i + 1][k];

      for (size_t j = 0; j < R.width; ++j) {
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
      }
    }
  }

  size_t k = 0;
  unsigned int rg = 0;

  for (size_t i = 0; i < R.height; ++i) {
    for (size_t j = k; j < R.width; ++j) {
      if (R.data[i][j] > eps) {
        rg++;
        k = j + 1;
        break;
      }
    }
  }
  return rg;
}

template <class Type> 
void matrix<Type>::trans() {
  matrix A(width, height);
  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < width; ++j) {
      if (i != j) {
        A.data[j][i] = data[i][j];
        A.data[i][j] = data[j][i];
      }
    }
  }
  *this = A;
}
#endif//MATRIX_FUNCTIONS_H 