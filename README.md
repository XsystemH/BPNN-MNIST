# BPNN-MNIST

A demo to Machine Learning, CS1950, SJTU

## 一些废话

关于AI的使用，飘子逸其实非常熟悉，从军训做政工开始就熟练掌握了GPT提示词的编写，还经过了各种水课作业的千锤百炼，可以说是炉火纯青。

相信你们看到这个仓库的时候，应该也差不多成为了熟练的ChatGPT使用者。

但是，说真的，在飘子逸在大一挣扎的这一年里，尽管耳朵里充斥着AI相关的词汇，也听过几回关于AI的讲座，但是对于AI基本上没有过系统的了解，
也没能沉下心来自己去了解。这个Demo的目的是希望能够给大家一个开始自己动手的契机，不会太难，也不会占用大家太多的时间。
（估计看到这个的时候是13、14周了，还是把更多的时间留给期末和大作业吧）

为了不给大家带来额外的负担，demo的语言选取为C++，也仅仅是实现了一个很基础的基于神经网络的数字识别。
（当然，如果有同学能力较强的话，完全可以无视这个框架，自己实现）

## 基于反向传播神经网络的数字识别

### 参考资料

推荐论文:

[Handwritten Digit Recognition with a Back-Propagation Network (1989)](https://proceedings.neurips.cc/paper_files/paper/1989/file/53c3bce66e43be4f209556518c2fcb54-Paper.pdf)

推荐视频(3b1b的系列视频):

[深度学习之神经网络的结构 Part 1 ver 2.0](https://www.bilibili.com/video/BV1bx411M7Zx/?share_source=copy_web&vd_source=4e87a3cc94a0b88cbc06001f2d08d6a8)

[深度学习之梯度下降法 Part 2 ver 0.9 beta](https://www.bilibili.com/video/BV1Ux411j7ri/?share_source=copy_web&vd_source=4e87a3cc94a0b88cbc06001f2d08d6a8)

[深度学习之反向传播算法 上/下 Part 3 ver 0.9 beta](https://www.bilibili.com/video/BV16x411V7Qg/?share_source=copy_web&vd_source=4e87a3cc94a0b88cbc06001f2d08d6a8)

### 数据集: MNIST

使用`mnist_reader`加载`MNIST`数据集非常方便，它会将数据加载为简单的`std::vector`类型，以便处理图像和标签。

#### `mnist_reader`库的数据格式

使用 mnist_reader 加载的数据格式为：

图像数据：每张图像为一个`28x28`像素的灰度图，展平成一个包含`784`个元素的`std::vector<uint8_t>`，数值范围在 [0, 255] 之间。

标签数据：标签是每张图像对应的数字（0-9），格式为`std::vector<uint8_t>`

#### 使用`mnist_reader`加载数据

首先，确保在你的 C++ 项目中引入了`mnist_reader`。你可以从[mnist-cpp](https://github.com/wichtounet/mnist) 获取这个库并将其集成到你的项目中。(这一步已经完成，可以直接使用)

下面是一个示例，展示如何加载训练数据和测试数据：

```c++
#include "mnist_reader.hpp"
#include "mnist_reader_less.hpp"
#include <iostream>
#include <vector>

// 加载MNIST数据集
int main() {
    // 加载MNIST数据集，路径为存储MNIST数据集的文件夹
    auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("mnist_data");

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
```

### src部分

## 学有余力 → Transformer

[Attention Is All You Need](https://user.phil.hhu.de/~cwurm/wp-content/uploads/2020/01/7181-attention-is-all-you-need.pdf)
