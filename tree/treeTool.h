#ifndef _TREE_TOOL_H
#define _TREE_TOOL_H

#include "../state.h"
#include <vector>
#include <queue>
#include <type_traits> // 引入type_traits头文件，用于去除指针修饰符
using namespace std ;

template <typename T>
class TreeNode{
    public:
        T data ;
        vector<TreeNode*> children;
};

namespace TreeTool{
    template <auto object, class T=std::decay_t<decltype (*object)>>
    class Data{
        public:
            std::remove_pointer<T>::type operator() (TreeNode<T>& node){
                return *node.data ; // 返回原始类型，而不是指针类型
            }
    };

    static int val = 100; // 定义一个静态变量，用于作为非类型模板参数
    Data<&val> data ; // 创建一个Data对象，让编译器自动推导出T的类型
};

#endif
