#include "../include/tensor.hpp"
#include <iostream>
#include <chrono>

int main() {
    
    std::vector<float> dataX = {};
    std::vector<float> dataY = {}; 

    for (int i = 0; i < 1048576; i++) {
        dataX.push_back(i);
        dataY.push_back(i);
    }
     
    sheath::Tensor X(dataX,1024,1024);
    sheath::Tensor Y(dataY,1024,1024);

    std::cout << "Tensor X" << std::endl;
    X.display();

    std::cout << "Tensor Y" << std::endl;
    Y.display();

    std::cout << "Sum" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto Z = X+Y;
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    Z.display();

    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;


    return 0;


}