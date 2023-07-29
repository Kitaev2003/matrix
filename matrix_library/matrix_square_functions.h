#ifndef MATRIX_SQUARE_FUNCTIONS_H
#define MATRIX_SQUARE_FUNCTIONS_H

template <class Type>
matrix_square<Type>::matrix_square(unsigned int in_size) : size(in_size) {
  height = size;
  width = size;

  data.resize(size);
  for (RowIterator iter = data.begin(); iter < data.end(); ++iter) {
    iter->resize(size);
  }
}

template <class Type>
matrix_square<Type>::matrix_square(const unsigned int n, const unsigned int m) {
  assert(n == m);
  height = n;
  width = m;
  size = n;

  data.resize(size);
  for (RowIterator iter = data.begin(); iter < data.end(); ++iter) {
    iter->resize(size);
  }
}

template <class Type> 
matrix_square<Type>::~matrix_square() {
  for (RowIterator iter = data.begin(); iter < data.end(); ++iter) {
    iter->resize(0);
  }

  data.resize(0);
}

template <class Type> 
Type matrix_square<Type>::tr() {
  Type trace = 0;

  for (RowIterator i = data.begin(); i < data.end(); ++i) {
    for (ColIterator j = i->begin(); j < i->end(); ++j) {
      trace += *j;
    }
  }
  return trace;
}

template <class Type> 
Type matrix_square<Type>::det() {
  matrix_square R = *this;
  Type deter = 1;

  size_t qua = 1;
  size_t sign = 0;

  for (size_t c = 0; c < R.size; ++c) {
    while (fabs(R.data[c][c]) < eps && (c + qua) < R.size) {
      line swap = R.data[c];
      R.data[c] = R.data[c + qua];
      R.data[c + qua] = swap;

      qua++;
      sign++;
    }
    qua = 1;
  }

  size_t k = 0;

  Type val1, val2;
  while (k < (R.size - 1)) {
    for (size_t i = k; i < (R.size - 1); ++i) {
      if (fabs(R.data[k][k]) < eps) {
        return 0;
      }
      val1 = R.data[k][k];

      if (fabs(R.data[i + 1][k]) < eps) {
        continue;
      }
      val2 = R.data[i + 1][k];

      for (size_t j = 0; j < R.size; ++j) {
        R.data[i + 1][j] = R.data[i + 1][j] - R.data[k][j] * (val2 / val1);
      }
    }
    deter *= R.data[k][k];
    k++;
  }

  deter *= R.data[k][k];

  if (fabs(deter) < eps) {
    return 0;
  }

  return deter * std::pow(-1, sign);
}
#endif //MATRIX_SQUARE_FUNCTIONS_H