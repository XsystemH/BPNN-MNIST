//
// Created by 13199 on 2024/9/4.
//
#include "mnist_reader/mnist_reader.hpp"
#include <iostream>
#include <vector>

// 加载MNIST数据集
int main() {
  // 加载MNIST数据集，路径为存储MNIST数据集的文件夹
  auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("../mnist_data");

  // 训练数据
  std::vector<std::vector<uint8_t>> train_images = dataset.training_images;
  std::vector<uint8_t> train_labels = dataset.training_labels;

  // 测试数据
  std::vector<std::vector<uint8_t>> test_images = dataset.test_images;
  std::vector<uint8_t> test_labels = dataset.test_labels;

  // 输出训练集和测试集的大小
  std::cout << "Training set size: " << train_images.size() << " images\n";
  std::cout << "Test set size: " << test_images.size() << " images\n";

  return 0;
}