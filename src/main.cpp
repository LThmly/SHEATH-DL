#include "../include/tensor.hpp"
#include <iostream>
#include <chrono>

int main() {
    
    std::vector<float> dataXBig = {};
    std::vector<float> dataYBig = {}; 

    std::vector<float> dataX = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<float> dataY = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 1048576; i++) {
        dataXBig.push_back(i);
        dataYBig.push_back(i);
    }
     
    sheath::Tensor XBig(dataXBig,1024,1024);
    sheath::Tensor YBig(dataYBig,1024,1024);

    sheath::Tensor X(dataX, 3, 3);
    sheath::Tensor Y(dataY, 3, 3);

    std::cout << "Tensor X" << std::endl;
    X.display();

    std::cout << "Tensor Y" << std::endl;
    Y.display();

    std::cout << "Hadamard Product" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto Z = X.hadamard(Y);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    Z.display();

    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;


    return 0;


}