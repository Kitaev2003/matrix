#include "../matrix.hpp"

matrix::matrix(const unsigned int n, const unsigned int m) : width(m), height(n){
    data.resize(height);

    for(row iter = data.begin(); iter < data.end(); ++iter){
        iter->resize(width);
    }
}

matrix::matrix(matrix& rhs){
    height = rhs.height;
    width = rhs.width;

    data = rhs.data;
}

matrix::~matrix(){
    for(row iter = data.begin(); iter < data.end(); ++iter){
        iter->resize(0);
    } 

    data.resize(0); 
}

RowIterator matrix::begin(){
    RowIterator A(data.begin());
    return A;
}

RowIterator matrix::end(){
    RowIterator A(data.end());
    return A;
}

void matrix::scan(){
    for(row i = data.begin(); i < data.end(); ++i){
        for(ColIterator j = i->begin(); j < i->end(); ++j){
            std::cin >> *j;
        }
    }
}

void matrix::print(){
    std::cout << "Height:" << height <<"\nWidth:" << width << std::endl;

    for(row i = data.begin(); i < data.end(); ++i){
        for(ColIterator j = i->begin(); j < i->end(); ++j){
            std::cout << *j << " ";
        }
        std::cout<< std::endl;
    }
}

unsigned int matrix::rang(){
    matrix R = *this;

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
    unsigned int rg = 0;

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

void matrix::trans(){
    matrix A(width, height);
    for(size_t i = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j){
            if(i != j){
                A.data[j][i] = data[i][j];
                A.data[i][j] = data[j][i];
            }
        }
    }
    *this = A;
}