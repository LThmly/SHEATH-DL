#include "../include/tensor.hpp"
#include <stdexcept>
#include <string>


// Zero Tensor
Tensor::Tensor(size_t rows, size_t cols) : rows(rows), cols(cols) {
    // Creates rows x cols tensor with zero values
    data.resize(rows * cols, 0.0f);
}

// Tensor with Data
Tensor::Tensor(std::vector<float> data, size_t rows, size_t cols) : data(data), rows(rows), cols(cols) {
    // Creates rows x cols tensor with given data & checks if valid
    if (data.size() != rows * cols) {
        throw std::invalid_argument("Invalid dimensions. Data size =  " + std::to_string(data.size()) + ", but rows * cols = " + std::to_string(rows * cols));
    }
}

// Tensor Shape
std::tuple<size_t, size_t> Tensor::shape() {
    return std::make_tuple(rows, cols);
}

// Display Tensor
void Tensor::display() {
    size_t col = 0;
    for (float element : data) {
        std::cout << element << ' ';
        col++;
        if (col == cols) {
            std::cout << std::endl;
            col = 0;
        }
     }
}

// Overloading
float& Tensor::operator[](size_t r, size_t c) {
    return data[r * cols + c];
}