cmake_minimum_required(VERSION 3.10)
project(SHEATH-DL)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(RunTensor 
    src/main.cpp 
    src/tensor.cpp
)