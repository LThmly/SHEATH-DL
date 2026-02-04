#include "../include/tensor.hpp"
#include <iostream>

int main() {
    Tensor T = Tensor(2,2);

    std::cout <<  "(" << std::get<0>(T.shape()) << ", " << std::get<1>(T.shape()) << ")";

    return 0;


}