#include <iostream> // 包含输入输出流头文件
using namespace std; // 使用命名空间 std

// 定义一个组件类，接受一个模板参数 T
template <typename T>
class Component {
public:
    // 定义一个构造函数，接受一个 T 类型的参数
    Component(T slot) {
        // 将参数赋值给成员变量
        this->slot = slot;
    }

    // 定义一个 render 方法，用于渲染组件
    void render() {
        // 输出固定内容
        cout << "This is a component with a slot." << endl;
        // 调用成员变量，即插槽内容
        this->slot(); // 注意要加上 this 指针
    }

private:
    // 定义一个 T 类型的成员变量，用于存储插槽内容
    T slot;
};

int main() {
    // 创建一个组件对象，传入一个 lambda 表达式作为插槽内容
   Component<int> comp(  {
        // 输出自定义内容
        cout << "This is the slot content." << endl;
        return 0;
    });



    // 调用 render 方法，渲染组件
    comp.render(); // 注意只有一个分号

    return 0;
}
