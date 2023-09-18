#include <iostream>
#include <functional>

// 定义一个比较类，用于封装一个int值
class Compare {
  private:
    int x; // 用于存储工厂函数传入的int值
  public:
    // 构造函数，接收一个int值，初始化x
    Compare(int x) {
      this->x = x;
    }
    // 重载()运算符，接收一个int值，比较它与x是否相等
    bool operator()(int y) {
      return x == y;
    }
};

// 定义一个工厂函数，接收一个int值，返回一个Compare对象
Compare factory(int x) {
  // 创建一个Compare对象，传入x
  Compare c(x);
  // 返回这个Compare对象
  return c;
}

int main() {
  // 调用工厂函数，传入10，得到一个Compare对象f
  auto f = factory(10);
  // 调用f，传入10，输出true
  std::cout << f(10) << std::endl;
  // 调用f，传入20，输出false
  std::cout << f(20) << std::endl;
  return 0;
}
