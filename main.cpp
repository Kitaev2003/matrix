#include "matrix.hpp"

int main(int argc, char* argv[]){
    matrix A(3, 3);
    std::cin >> A;

    std::cout << A.det();
    return 0;
}

