#include "matrix.h"

int main(){
    matrix_square<double> A(3, 3);
    std::cin >> A;
    matrix<double> C = A * 2;
    matrix<double> B = A - C;
    A += B;
    B -= C;
    double num = B[1][1];
    std::cout << A << B << C;
    std::cout << num;
    return 0;
}

