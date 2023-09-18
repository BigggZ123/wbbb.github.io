#include <iostream>
using namespace std ;

// 基类 A 的定义
class A {
public:
    // 构造函数
    A(int x) : x(x) {}

    // 获取 x 的值
    int getX() {
        return x;
    }

private:
    int x; // 基类特有的成员变量
};

// 子类 B 的定义
class B : public A {
public:
    // 构造函数
    B(int x, int y) : A(x), y(y) {}

    // 获取 y 的值
    int getY() {
        return y;
    }

private:
    int y; // 子类特有的成员变量
};

// 测试代码
int main() {
    // 创建一个 B 类型的对象
    B b(10, 20);

    // 使用基类指针来指向子类对象
    A* a = &b;

    // 使用基类指针来调用基类和子类共有的成员函数
    std::cout << "a->getX(): " << a->getX() << std::endl; // 输出 10

    // 使用 dynamic_cast 来将基类指针转换为子类指针
    B* b2 = dynamic_cast<B*>(a);
    if (b2) { // 如果转换成功
        // 使用子类指针来调用子类特有的成员函数和变量
        std::cout << "b2->getY(): " << b2->getY() << std::endl; // 输出 20
        std::cout << "b2->y: " << b2->y << std::endl; // 输出 20
    }

    return 0;
}
