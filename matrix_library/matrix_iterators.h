#ifndef MATRIX_ITERATORS_H
#define MATRIX_ITERATORS_H

template <class Type>
matrix<Type>::RowIterator::RowIterator() {}

template <class Type>
matrix<Type>::RowIterator::~RowIterator() = default;

template <class Type>
typename matrix<Type>::RowIterator& matrix<Type>::RowIterator::operator = (matrix<Type>::RowIterator const& rhs) {
    iter = rhs.iter;
    return *this;
}

template <class Type>
bool matrix<Type>::RowIterator::operator != (matrix<Type>::RowIterator const& rhs) {
    return (iter != rhs.iter);
}

template <class Type>
bool matrix<Type>::RowIterator::operator == (matrix<Type>::RowIterator const& rhs) {
    return (iter == rhs.iter);
}

template <class Type>
typename matrix<Type>::RowIterator& matrix<Type>::RowIterator::operator++() {
    ++iter;
    return *this;
}

template <class Type>
typename matrix<Type>::RowIterator::ColIterator matrix<Type>::RowIterator::begin() {
    return (*p).begin();
}

template <class Type>
typename matrix<Type>::RowIterator::ColIterator matrix<Type>::RowIterator::end() {
    return (*p).end();
}
#endif //MATRIX_ITERATORS_H