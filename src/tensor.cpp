#include "../include/tensor.hpp"
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iostream>

namespace sheath {
    
    // Zero Tensor
    TensorHidden::TensorHidden(const size_t rows, const size_t cols) : rows(rows), cols(cols) {
        // Creates rows x cols tensor with zero values
        data.resize(rows * cols, 0.0f);
    }

    // Tensor with Data
    TensorHidden::TensorHidden(const std::vector<float>& data, const size_t rows, const size_t cols) : data(data), rows(rows), cols(cols) {
        // Creates rows x cols tensor with given data & checks if valid
        if (data.size() != rows * cols) {
            throw std::invalid_argument("Invalid dimensions. Data size =  " + std::to_string(data.size()) + ", but rows * cols = " + std::to_string(rows * cols));
        }
    }

    // Tensor Shape
    std::tuple<size_t, size_t> TensorHidden::shape() const {
        return std::make_tuple(rows, cols);
    }

    // Tensor Size
    unsigned int TensorHidden::size() const {
        return rows * cols;
    }

    // Display Tensor
    void TensorHidden::display() const {
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

    // Access Elements
    float& TensorHidden::operator[](const size_t r, const size_t c) {
        return data[r * cols + c];
    }

    // Access Elements 
    const float& TensorHidden::operator[](const size_t r, const size_t c) const {
        return data[r * cols + c];
    }

    // Operations
    std::shared_ptr<TensorHidden> TensorHidden::mult(const std::shared_ptr<TensorHidden>& other) const {
        if (cols != other->rows) {
            throw std::invalid_argument("Invalid dimensions. Cols of first matrix must equal rows of second matrix.");
        }

        auto output = std::make_shared<TensorHidden>(rows, other->cols);
        unsigned int total_size = this->size();

        if (total_size < 64) {
            // Naive Algorithm
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < other->cols; j++) {
                    float sum = 0.0f;
                    for (size_t k = 0; k < cols; k++) {
                        sum += (*this)[i, k] * (*other)[k, j];
                    }
                    (*output)[i, j] = sum;
                }
            }
        } else {
            // Tiling Algorithm
            size_t b = 32; // block size
            for (size_t ii = 0; ii < rows; ii += b) {
                for (size_t jj = 0; jj < other->cols; jj += b) {
                    for (size_t kk = 0; kk < cols; kk += b) {
                        size_t ii_bound = std::min(ii + b, rows);
                        size_t jj_bound = std::min(jj + b, other->cols);
                        size_t kk_bound = std::min(kk + b, cols);

                        for (size_t i = ii; i < ii_bound; ++i) {
                            for (size_t k = kk; k < kk_bound; ++k) {
                                float a_ik = (*this)[i, k];
                                for (size_t j = jj; j < jj_bound; ++j) {
                                    (*output)[i, j] += a_ik * (*other)[k, j];
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return output;
    }

    // Transpose
    void TensorHidden::T() {
        std::vector<float> newData;
        newData.reserve(rows * cols);
        
        for (size_t i = 0; i < cols; i++) {
            for (size_t j = i; j < rows * cols; j += cols) {
                newData.push_back(data[j]);
            }
        }
        
        data = std::move(newData);
        std::swap(rows, cols);
    }
}