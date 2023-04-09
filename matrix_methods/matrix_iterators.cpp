#include "../matrix.hpp"

RowIterator::RowIterator(row p_) : p(p_) {}

RowIterator::RowIterator(const RowIterator& it) : p(it.p) {}

RowIterator& RowIterator::operator=(RowIterator const& rhs){
    p = rhs.p;
    return *this;
}
bool RowIterator::operator != (RowIterator const& rhs) const{
    return (p != rhs.p);
}

RowIterator& RowIterator::operator++(){
    ++p;
    return *this;
}

ColIterator RowIterator::begin(){
    return (*p).begin();
}

ColIterator RowIterator::end(){
    return (*p).end();
}