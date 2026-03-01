#include "../include/tensor.hpp"
#include <iostream>

int main() {
    sheath::Tensor X({8, 4, -2, 1, 3, 7, 2, 4, 3},3,3);
    sheath::Tensor Y({7, 2, 1, 5, 1, 9, 6, 0, 6},3,3);

    std::cout << "Tensor X" << std::endl;
    X.display();

    std::cout << "Tensor Y" << std::endl;
    Y.display();

    std::cout << "Product" << std::endl;
    auto Z = X*Y;
    Z.display();

    return 0;


}