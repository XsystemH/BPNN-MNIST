cmake_minimum_required(VERSION 3.22)
project(MNIST)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(MNIST
        src/main.cpp
        src/NeuralNetwork.cpp
        src/NeuralNetwork.h)
