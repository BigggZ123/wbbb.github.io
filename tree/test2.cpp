#include <iostream>
#include <vector>
using namespace std ;

// 基类 TreeNode 的定�?
template <typename T>
class TreeNode {
protected:
    T data; // 节点数据
    std::vector<TreeNode<T>*> children; // 子节点指针的 vector
public:
    // 构造函�?
    TreeNode(T data) : data(data) {}

    // 虚析构函�?
    virtual ~TreeNode() {
        // 释放所有子节点指针所指向的内�?
        for (auto child : children) {
            delete child;
        }
    }

    // 虚函数：打印节点数据
    virtual void print() {
        std::cout << "TreeNode: " << data << std::endl;
    }

    // 添加子节�?
    void addChild(TreeNode<T>* child) {
        children.push_back(child);
    }
};

// 子类 ChildNode 的定�?
template <typename T, typename U>
class ChildNode : public TreeNode<T> {
public:
    // 构造函�?
    ChildNode(T data, U extra) : TreeNode<T>(data), extra(extra) {}

    // 虚析构函�?
    virtual ~ChildNode() override {
        // 不需要做任何事，基类的虚析构函数会被自动调用
    }

    // 虚函数：打印节点数据和额外数�?
    virtual void print() override {
        std::cout << "ChildNode: " << this->data << ", " << extra << std::endl;
    }

private:
    U extra; // 额外数据
};

// 基类 TreeNode 和子�? ChildNode 的定义与之前相同

// 测试代码
int main() {
    // 创建一�? TreeNode<int> 的对�?
    TreeNode<int>* root = new TreeNode<int>(1);

    // 创建两个 ChildNode<int, string> 的对�?
    ChildNode<int, string>* child1 = new ChildNode<int, string>(2, "a");
    ChildNode<int, string>* child2 = new ChildNode<int, string>(3, "b");

    // 使用子类�? addChild �? vector 中添加子类的指针
    child1->addChild(child2);

    // 使用子类�? print 来打印节点数据和额外数据
    child1->print(); // 输出 ChildNode: 2, a
    child2->print(); // 输出 ChildNode: 3, b

    // 释放根节点和子节点指针，会自动调用所有节点的虚析构函�?
    delete root;
    delete child1;
    delete child2;

    return 0;
}
