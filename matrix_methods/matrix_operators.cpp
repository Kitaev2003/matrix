#include "../matrix.hpp"

const std::ostream& operator << (const std::ostream& os, const matrix& A){//friend
    std::cout << "Height:" << A.height <<"\nWidth:" << A.width << std::endl;

    for(size_t i = 0; i < A.width; ++i){
        for(size_t j = 0; j < A.width; ++j){
            std::cout << A.data[i][j] << " ";
        }
        std::cout<< std::endl;
    }
    return os;
} 

const std::istream& operator >> (const std::istream& is, matrix& A){//friend
    double val;

    for(size_t i = 0; i < A.height; ++i){
        for(size_t j = 0; j < A.width; ++j){
            std::cin >> val;
            A.data[i][j] = val;
        }
    }
    return is;
}

matrix matrix::operator * (matrix& B){//friend
    assert(this->width == B.height);

    matrix C(this->height, B.width); 

    for (size_t ic = 0; ic < C.height; ++ic ){
        for(size_t jc = 0; jc < C.width; ++jc){
            for(size_t k = 0; k < this->width; ++k){
                C.data[ic][jc] += this->data[ic][k]*B.data[k][jc];
            }
        }
    }
    return C;
}

matrix matrix::operator * (double val){//friend
    matrix C = *this;

    for (size_t i = 0; i < this->height; ++i){
        for(size_t j = 0; j < this->width; ++j){
            C.data[i][j] *= val;
        }
    }
    return C;
}

matrix& matrix::operator += (matrix& B){
    assert(this->width == B.width);
    assert(this->height == B.height);

    for (size_t i = 0; i < this->height; ++i){
        for(size_t j = 0; j < this->width; ++j){
            this->data[i][j] = this->data[i][j] + B.data[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator -= (matrix& B){
    assert(this->width == B.width);
    assert(this->height == B.height);

    for (size_t i = 0; i < this->height; ++i){
        for(size_t j = 0; j < this->width; ++j){
            this->data[i][j] = this->data[i][j] - B.data[i][j];
        }
    }
    return *this;
}

matrix operator + (matrix& A, matrix& B){
    matrix C = A;
    C += B;
    return C;
}

matrix operator - (matrix& A, matrix& B){
    matrix C = A;
    C -= B;
    return C;
}

matrix_square& matrix_square::operator *= (matrix_square &B){
    assert(this->size == B.size);

    matrix_square C(this->size); 

    for (size_t ic = 0; ic < C.size; ++ic ){
        for(size_t jc = 0; jc < C.size; ++jc){
            for(size_t k = 0; k < C.size; ++k){
                C.data[ic][jc] += this->data[ic][k]*B.data[k][jc];
            }
        }
    }
    *this = C;
    return *this;
}

matrix_square operator* (matrix_square& A, matrix_square &B){
    matrix_square C = A;
    C *= B;
    return C;
}