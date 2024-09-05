//
// Created by 13199 on 2024/9/4.
//

#ifndef MNIST_NEURALNETWORK_H
#define MNIST_NEURALNETWORK_H


#include <vector>
#include <random>

class NeuralNetwork {
private:
  std::vector<std::vector<double>> weights1; // 输入层到隐藏层
  std::vector<std::vector<double>> weights2; // 隐藏层到输出层
  std::vector<double> biases1;
  std::vector<double> biases2;

public:
  NeuralNetwork(int input_size, int hidden_size, int output_size) {
    weights1 = initialize_weights(input_size, hidden_size);
    weights2 = initialize_weights(hidden_size, output_size);
    biases1 = std::vector<double>(hidden_size, 0.0);
    biases2 = std::vector<double>(output_size, 0.0);
  }

  std::vector<double> forward(const std::vector<double>& input) {

  }

private:
  static std::vector<std::vector<double>> initialize_weights(int m, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    std::vector<std::vector<double>> weights(m, std::vector<double>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        weights[i][j] = dis(gen);
      }
    }

    return weights;
  }
};


#endif //MNIST_NEURALNETWORK_H
