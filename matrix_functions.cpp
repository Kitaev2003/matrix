#include "matrix.hpp"

matrix::matrix(const size_t m, const size_t n){
    height = m;//i
    width = n;//j

    data.resize(m);

    for(row iter = data.begin(); iter < data.end(); ++iter){
        iter->resize(n);
    }
}

matrix::~matrix(){
    for(row iter = data.begin(); iter < data.end(); ++iter){
        iter->resize(0);
    } 

    data.resize(0); 
}

void matrix::scan(){
    for(size_t i = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j){
            std::cin >> data[i][j];
        }
    }
}

void matrix::print(){
    std::cout << "Height:" << height <<"\nWidth:" << width << std::endl;

    for(size_t i = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j){
            std::cout << data[i][j] << " ";
        }
        std::cout<< std::endl;
    }
}

const std::ostream& operator << (const std::ostream &os, matrix& A){
    A.print();
    return os;
} 

const std::istream& operator >> (const std::istream &is, const matrix& A){
    double val;
    for(size_t i = 0; i < A.height; ++i){
        for(size_t j = 0; j < A.width; ++j){
            val = A.data[i][j];
            std::cin >> val;
        }
    }
    return is;
}

matrix operator * (matrix &A, matrix &B){
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

matrix operator + (matrix &A, matrix &B){
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

size_t matrix::rang(matrix A){
    matrix R = A;

    size_t qua = 1;
    for(size_t c = 0; c < R.height; ++c){
        while(fabs(R.data[c][c]) < eps && (c+qua) < R.height){
            line swap = R.data[c];
            R.data[c] = R.data[c+qua];
            R.data[c+qua] = swap;
            
            qua++;
        }
        qua = 1;
    }

    double val1, val2;
    for(size_t k = 0; k < (R.height-1); ++k){
        for(size_t i = k; i < (R.height-1); ++i){
            if(fabs(R.data[k][k]) < eps || fabs(R.data[i+1][k]) < eps){
                continue;
            }
            val1 = R.data[k][k];
            val2 = R.data[i+1][k];

            for(size_t j = 0; j < R.width;  ++j){       
                R.data[i+1][j] = R.data[i+1][j] - R.data[k][j] * (val2 /val1);
            }
        }
    }

    size_t k = 0;
    size_t rg = 0;

    for(size_t i = 0; i < R.height; ++i){
        for(size_t j = k; j < R.width; ++j){
            if(R.data[i][j] > eps){
                rg++;
                k = j + 1;
                break;
            }
        }
    }

    return rg;

}

double matrix::det(matrix A){
    assert(A.height == A.width);

    matrix R = A;
    double deter = 1; 

    size_t qua = 1;
    size_t sign = 0;

    for(size_t c = 0; c < R.height; ++c){
        while(fabs(R.data[c][c]) < eps && (c+qua) < R.height){
            line swap = R.data[c];
            R.data[c] = R.data[c+qua];
            R.data[c+qua] = swap;
            
            qua++;
            sign++;
        }
        qua = 1;
    }

    size_t k = 0;

    double val1, val2;
    while(k < (R.height-1)){
        for(size_t i = k; i < (R.height-1); ++i){
            if(fabs(R.data[k][k]) < eps){
                return 0;
            }
            val1 = R.data[k][k];

            if(fabs(R.data[i+1][k]) < eps){
                continue;
            }
            val2 = R.data[i+1][k];

            for(size_t j = 0; j < R.width;  ++j){       
                R.data[i+1][j] = R.data[i+1][j] - R.data[k][j] * (val2 /val1);
                R.print();
            }
        }
        deter *=  R.data[k][k];
        k++;
    }

    deter *= R.data[k][k];

    if(fabs(deter) < eps ){
        return 0;
    }

    return deter * std::pow(-1, sign); 
}