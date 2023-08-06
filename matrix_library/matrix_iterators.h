#ifndef MATRIX_ITERATORS_H
#define MATRIX_ITERATORS_H
#include "matrix.h"

template <class Type> 
typename matrix<Type>::RowIterator matrix<Type>::begin() {
  RowIterator Iterator(data.begin());
  return Iterator;
}

template <class Type> 
typename matrix<Type>::RowIterator matrix<Type>::end() {
  RowIterator Iterator(data.end());
  return Iterator;
}

template <class Type>
matrix<Type>::RowIterator::RowIterator(const matrix<Type>::RowIterator &rhs) {
  iter = rhs.iter;
}

template <class Type>
typename matrix<Type>::RowIterator &
matrix<Type>::RowIterator::operator=(const matrix<Type>::RowIterator &rhs) {
  iter = rhs.iter;
  return *this;
}

template <class Type>
matrix<Type>::RowIterator::RowIterator(
    const typename std::vector<std::vector<Type>>::iterator &rhs) {
  iter = rhs;
}

template <class Type>
std::vector<Type> &matrix<Type>::RowIterator::operator*() const {
  return *(iter);
}

template <class Type>
bool matrix<Type>::RowIterator::operator!=(
    matrix::RowIterator const &rhs) const {
  return (iter != rhs.iter);
}

template <class Type>
bool matrix<Type>::RowIterator::operator==(
    matrix::RowIterator const &rhs) const {
  return (iter == rhs.iter);
}

template <class Type>
typename matrix<Type>::RowIterator &matrix<Type>::RowIterator::operator++() {
  ++iter;
  return *this;
}

template <class Type>
typename matrix<Type>::RowIterator::ColIterator
matrix<Type>::RowIterator::begin() {
  ColIterator Iterator(iter->begin());
  return Iterator;
}

template <class Type>
typename matrix<Type>::RowIterator::ColIterator
matrix<Type>::RowIterator::end() {
  ColIterator Iterator(iter->end());
  return Iterator;
}

template <class Type>
matrix<Type>::RowIterator::ColIterator::ColIterator(
    const matrix<Type>::RowIterator::ColIterator &rhs) {
  iter = rhs.iter;
}

template <class Type>
typename matrix<Type>::RowIterator::ColIterator &
matrix<Type>::RowIterator::ColIterator::operator=(
    const typename matrix<Type>::RowIterator::ColIterator &rhs) {
  iter = rhs.iter;
}

template <class Type>
matrix<Type>::RowIterator::ColIterator::ColIterator(
    const typename std::vector<Type>::iterator &rhs) {
  iter = rhs;
}

template <class Type>
Type &matrix<Type>::RowIterator::ColIterator::operator*() const {
  return *(iter);
}

template <class Type>
bool matrix<Type>::RowIterator::ColIterator::operator!=(
    matrix::RowIterator::ColIterator const &rhs) const {
  return (iter != rhs.iter);
}

template <class Type>
bool matrix<Type>::RowIterator::ColIterator::operator==(
    matrix::RowIterator::ColIterator const &rhs) const {
  return (iter == rhs.iter);
}

template <class Type>
typename matrix<Type>::RowIterator::ColIterator &
matrix<Type>::RowIterator::ColIterator::operator++() {
  ++iter;
  return *this;
}
#endif // MATRIX_ITERATORS_H