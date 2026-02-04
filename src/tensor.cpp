#include "../include/tensor.hpp"
#include <stdexcept>
#include <string>


// Zero Tensor
Tensor::Tensor(const size_t rows, const size_t cols) : rows(rows), cols(cols) {
    // Creates rows x cols tensor with zero values
    data.resize(rows * cols, 0.0f);
}

// Tensor with Data
Tensor::Tensor(const std::vector<float>& data, const size_t rows, const size_t cols) : data(data), rows(rows), cols(cols) {
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
void Tensor::display() const {
    size_t col = 0;
    for (const float element : data) {
        std::cout << element << ' ';
        col++;
        if (col == cols) {
            std::cout << std::endl;
            col = 0;
        }
     }
}

// Access Elements ([row,col]  & 0 index)
float& Tensor::operator[](const size_t r, const size_t c) {
    return data[r * cols + c];
}

// Operations

// Transpose
void Tensor::T() {
    std::vector<float> newData;
    for (size_t i = 0; i < rows ; i++) {
        for (size_t j = i; j < rows * cols; j+= cols) {
            newData.push_back(data[j]);
        }
    }
    data = newData;
}