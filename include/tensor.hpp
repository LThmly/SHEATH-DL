#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <tuple>

class Tensor;

using TensorPtr = std::shared_ptr<Tensor>;

class Tensor {
    public:
        std::vector<float> data;

        // Dimensions
        size_t rows;
        size_t cols;

        // Constructors
        Tensor(size_t rows, size_t cols);
        Tensor(std::vector<float> data, size_t rows, size_t cols);

        // Basic Info
        std::tuple<size_t, size_t> shape();
        void display();

        // Operations
        TensorPtr transpose();
        TensorPtr mult(const TensorPtr& other);
        TensorPtr add(const TensorPtr other);

        // Overloading
        float& operator[](size_t r, size_t c);
        const float& operator[](size_t row, size_t col) const;

};