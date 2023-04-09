#include "matrix.hpp"

int main(int argc, char* argv[]){
    matrix A(3, 3);
    std::cin >> A;
    for(RowIterator p = A.begin(); p != A.end(); ++p){
        for(col k = p.begin(); k != p.end(); ++k){
            std::cout << *k << std::endl;
        }
    }
}

