#include "../include/tensor.hpp"
#include <iostream>

int main() {
    Tensor X = Tensor({8, 4, -2, 1, 3, 7, 2, 4, 3},3,3);

    std::cout <<  "(" << std::get<0>(X.shape()) << ", " << std::get<1>(X.shape()) << ")" << std::endl;
    std::cout << "Initial Tensor:" << std::endl;
    X.display();

    X.T();

    std::cout << "Transpose Tensor:" << std::endl;
    X.display();

    std::cout << X[0,1] << std::endl;

    return 0;


}