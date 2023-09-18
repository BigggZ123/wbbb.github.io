#include <iostream>
using namespace std ;

// 定义树节点类
class TreeNode {
public:
    int val; // 节点的值
    TreeNode* left; // 左子节点指针
    TreeNode* right; // 右子节点指针
    // 构造函数
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 定义树类
class Tree {
private:
    TreeNode* root; // 根节点指针
public:
    // 构造函数
    Tree(TreeNode* r = NULL) : root(r) {}
    // 抽象的遍历函数
    void traverse(void (*func)(TreeNode*), char order = 'p') {
        // func 是一个函数指针，它指向一个接受树节点指针作为参数并返回void类型的函数
        // order 是一个字符，表示遍历的顺序，'p' 代表先序，'i' 代表中序，'s' 代表后序
        if (root == NULL) return; // 如果根节点为空，直接返回
        if (order == 'p') { // 如果是先序遍历
            func(root); // 调用传入的函数指针对根节点进行操作
            traverse(root->left, func, order); // 递归遍历左子树
            traverse(root->right, func, order); // 递归遍历右子树
        } else if (order == 'i') { // 如果是中序遍历
            traverse(root->left, func, order); // 递归遍历左子树
            func(root); // 调用传入的函数指针对根节点进行操作
            traverse(root->right, func, order); // 递归遍历右子树
        } else if (order == 's') { // 如果是后序遍历
            traverse(root->left, func, order); // 递归遍历左子树
            traverse(root->right, func, order); // 递归遍历右子树
            func(root); // 调用传入的函数指针对根节点进行操作
        } else { // 如果是无效的顺序参数
            cout << "Invalid order parameter!" << endl; // 输出错误信息
        }
    }
};

// 定义一个生成节点的操作函数
void generate(TreeNode* node) {
    if (node == NULL) return; // 如果节点为空，直接返回
    int left_val = rand() % 10; // 随机生成左子节点的值
    int right_val = rand() % 10; // 随机生成右子节点的值
    node->left = new TreeNode(left_val); // 创建左子节点并赋值给当前节点的左子节点指针
    node->right = new TreeNode(right_val); // 创建右子节点并赋值给当前节点的右子节点指针
}

// 定义一个打印节点的操作函数
void print(TreeNode* node) {
    if (node == NULL) return; // 如果节点为空，直接返回
    cout << node->val << " "; // 输出节点的值
}

// 定义一个删除节点的操作函数
void destroy(TreeNode* node) {
    if (node == NULL) return; // 如果节点为空，直接返回
    delete node; // 删除节点
}

int main() {
    srand(time(NULL)); // 设置随机数种子
    Tree tree(new TreeNode(0)); // 创建一棵树，根节点的值为0
    tree.traverse(generate, 'p'); // 以先序的方式生成一棵树
    tree.traverse(print, 'p'); // 以先序的方式打印一棵树
    cout << endl;
    tree.traverse(destroy, 's'); // 以后序的方式删除一棵树
    return 0;
}
