#include "matrix.hpp"

int main(int argc, char* argv[]){
    matrix_square A(3);
    matrix_square B(3);
    std::cin >> A >> B;
    std::cout << (A *= B);
    return 0;
}

