cmake_minimum_required(VERSION 3.22)
project(BPNN-MNIST)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(BPNN-MNIST
        src/main.cpp
        src/NeuralNetwork.h
        src/mnist_reader/mnist_reader.hpp)
