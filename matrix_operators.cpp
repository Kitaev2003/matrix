#include "matrix.hpp"

const std::ostream& operator << (const std::ostream& os,const matrix& A){
    std::cout << "Height:" << A.height <<"\nWidth:" << A.width << std::endl;

    for(size_t i = 0; i < A.width; ++i){
        for(size_t j = 0; j < A.width; ++j){
            std::cout << A.data[i][j] << " ";
        }
        std::cout<< std::endl;
    }
    return os;
} 

const std::istream& operator >> (const std::istream& is, matrix& A){
    double val;

    for(size_t i = 0; i < A.height; ++i){
        for(size_t j = 0; j < A.width; ++j){
            std::cin >> val;
            A.data[i][j] = val;
        }
    }
    return is;
}

matrix operator * (matrix& A, matrix& B){
    assert(A.width == B.height);

    matrix C(A.height, B.width); 

    for (size_t ic = 0; ic < C.height; ++ic ){
        for(size_t jc = 0; jc < C.width; ++jc){
            for(size_t k = 0; k < A.width; ++k){
                C.data[ic][jc] = C.data[ic][jc] + A.data[ic][k]*B.data[k][jc];
            }
        }
    }
    return C;
}

matrix operator * (double val, matrix& A){
    matrix C(A.width, A.height);

    for (size_t i = 0; i < C.height; ++i){
        for(size_t j = 0; j < C.width; ++j){
            C.data[i][j] = val * A.data[i][j];
        }
    }
    return C;
}

matrix operator + (matrix& A, matrix& B){
    assert(A.width == B.width);
    assert(A.height == B.height);

    matrix C(A.width, A.height);
    for (size_t i = 0; i < C.height; ++i){
        for(size_t j = 0; j < C.width; ++j){
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return C;
}

matrix operator - (matrix& A, matrix& B){
    assert(A.width == B.width);
    assert(A.height == B.height);

    matrix C(A.width, A.height);
    for (size_t i = 0; i < C.height; ++i){
        for(size_t j = 0; j < C.width; ++j){
            C.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    return C;
}