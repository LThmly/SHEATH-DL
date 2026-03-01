#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <tuple>
#include <initializer_list>

namespace sheath {

    // Hidden Tensor Class
    class TensorHidden {
        public:
            std::vector<float> data;

            // Dimensions
            size_t rows;
            size_t cols;

            // Constructors
            TensorHidden(size_t rows, size_t cols);
            TensorHidden(const std::vector<float>& data, size_t rows, size_t cols);

            // Basic Info
            std::tuple<size_t, size_t> shape() const;
            unsigned int size() const;
            void display() const;

            // Operations
            void T(); 
            std::shared_ptr<TensorHidden> mult(const std::shared_ptr<TensorHidden>& other) const;

            // Operator Overloading
            float& operator[](size_t r, size_t c);
            const float& operator[](size_t r, size_t c) const;
    };


    // Public Tensor Class
    class Tensor {
        private:
            std::shared_ptr<TensorHidden> internalTensor;
            
            Tensor(std::shared_ptr<TensorHidden> ptr) : internalTensor(ptr) {}

        public:
            Tensor(size_t rows, size_t cols) 
                : internalTensor(std::make_shared<TensorHidden>(rows, cols)) {}

            Tensor(std::initializer_list<float> data, size_t rows, size_t cols) 
                : internalTensor(std::make_shared<TensorHidden>(std::vector<float>(data), rows, cols)) {}

            std::tuple<size_t, size_t> shape() const {
                return internalTensor->shape();
            }

            unsigned int size() const {
                return internalTensor->size();
            }

            void display() const { 
                internalTensor->display(); 
            }
            
            void T() {
                internalTensor->T();
            }

            float& operator[](size_t r, size_t c) { 
                return (*internalTensor)[r, c]; 
            }
            
            const float& operator[](size_t r, size_t c) const { 
                return (*internalTensor)[r, c]; 
            }

            Tensor operator*(const Tensor& rhs) const {
                return Tensor(this->internalTensor->mult(rhs.internalTensor));
            }
    };

}