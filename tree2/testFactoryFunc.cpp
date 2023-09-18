#include <iostream>
#include <vector>
#include <functional>

// 一个工厂函数，根据给定的默认值生成一个equal函数
std::function<bool(int)> make_equal(int default_value) {
  // 返回一个lambda表达式，接受一个int参数，与默认值比较
  return default_value -> bool {
    return x == default_value;
  };
}

// 一个辅助函数，用于测试equal函数
void test_equal(std::function<bool(int)> equal, int x) {
  std::cout << "Testing " << x << " ... ";
  if (equal(x)) {
    std::cout << "Equal!\n";
  } else {
    std::cout << "Not equal!\n";
  }
}

int main() {
  // 一个存储equal函数指针的向量
  std::vector<std::function<bool(int)>> equals;

  // 批量生成不同默认值的equal函数，并添加到向量中
  for (int i = 0; i < 10; i++) {
    equals.push_back(make_equal(i));
  }

  // 测试每个equal函数
  for (auto equal : equals) {
    test_equal(equal, 5);
  }

  return 0;
}
