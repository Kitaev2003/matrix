#include "matrix.h"

typedef matrix<double>::Riterator Row;
typedef matrix<double>::Riterator::Citerator Col;
int main(){
    matrix<double> A(10, 10);
    matrix<double> B(A);
    matrix_square<int> C(3, 3);
    B.set((double)10);
    A.set(3.0);
    std::cout << A << B << A.rang()<< B.rang() << std::endl;
    auto Pair =  A.find(8.0);
    std::cout << A[0][0] << std::endl;
    return 0;
}

