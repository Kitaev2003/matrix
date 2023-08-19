#ifndef MATRIX_ITERATORS_H
#define MATRIX_ITERATORS_H
#include "matrix.h"

template <class Type> typename matrix<Type>::Riterator matrix<Type>::begin() {
  return Riterator(data, width);
}

template <class Type> typename matrix<Type>::Riterator matrix<Type>::end() {
  return Riterator(data + height, width);
}

template <class Type>
typename matrix<Type>::const_Riterator matrix<Type>::begin() const {
  return const_Riterator(data, width);
}

template <class Type>
typename matrix<Type>::const_Riterator matrix<Type>::end() const {
  return const_Riterator(data + height, width);
}

template <class Type>
RowIterator<Type>::RowIterator(const RowIterator<Type> &rhs) {
  Point = rhs.Point;
  width = rhs.width;
}

template <class Type>
RowIterator<Type> &RowIterator<Type>::operator=(const RowIterator<Type> &rhs) {
  width = rhs.width;
  Point = rhs.Point;
  return *this;
}

template <class Type>
RowIterator<Type>::RowIterator(Type **Point_, unsigned int width_)
    : Point(Point_), width(width_) {}

template <class Type>
typename RowIterator<Type>::reference RowIterator<Type>::operator*() const {
  return *Point;
}

template <class Type>
bool RowIterator<Type>::operator!=(RowIterator<Type> const &rhs) const {
  return (Point != rhs.Point);
}

template <class Type>
bool RowIterator<Type>::operator==(RowIterator<Type> const &rhs) const {
  return (Point == rhs.Point);
}

template <class Type> RowIterator<Type> &RowIterator<Type>::operator++() {
  ++Point;
  return *this;
}

template <class Type>
typename RowIterator<Type>::Citerator RowIterator<Type>::begin() {
  return Citerator(*Point);
}

template <class Type>
typename RowIterator<Type>::Citerator RowIterator<Type>::end() {
  return Citerator(*Point + width);
}

template <class Type>
typename RowIterator<Type>::const_Citerator RowIterator<Type>::begin() const {
  return const_Citerator(*Point);
}

template <class Type>
typename RowIterator<Type>::const_Citerator RowIterator<Type>::end() const {
  return const_Citerator(*Point + width);
}

template <class Type>
ColIterator<Type>::ColIterator(const ColIterator<Type> &rhs) {
  Point = rhs.Point;
}

template <class Type>
ColIterator<Type> &ColIterator<Type>::operator=(const ColIterator<Type> &rhs) {
  Point = rhs.Point;
}

template <class Type>
ColIterator<Type>::ColIterator(Type *Point_) : Point(Point_) {}

template <class Type>
typename ColIterator<Type>::reference &ColIterator<Type>::operator*() const {
  return *Point;
}

template <class Type>
bool ColIterator<Type>::operator!=(ColIterator<Type> const &rhs) const {
  return (Point != rhs.Point);
}

template <class Type>
bool ColIterator<Type>::operator==(ColIterator<Type> const &rhs) const {
  return (Point == rhs.Point);
}

template <class Type> ColIterator<Type> &ColIterator<Type>::operator++() {
  ++Point;
  return *this;
}
#endif // MATRIX_ITERATORS_H