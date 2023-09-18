#ifndef _I_TREE_H
#define _I_TREE_H

#include "../state.h"
#include <stack>
#include <vector>
#include <queue>

/*
* 为了visit操作打下基础
*/

template <typename T>
class iTree{
    /*
    * TreeNode所携带数据的访问与修改
    */
    public :
        virtual T&          data        ()          = 0 ;
        virtual iTree*      child       (int pos)   = 0 ;
        virtual int         degree      ()          = 0 ;
        virtual Status      erase       (int pos)   = 0 ;
        virtual Status      addChild    (int pos , iTree<T>* child)   = 0 ;
        virtual iTree*      parent      ()          = 0 ;
    /*
    * 实际Tree层面的操作
    */
    public :
        virtual iTree*      root        ()        ;
        virtual int         depth       ()        ;
        virtual bool        included    (iTree<T>* child);
        virtual Status      preOrder    (Status (*operate) (iTree<T>*));
        virtual Status      postOrder   (Status (*operate) (iTree<T>*));
        virtual Status      levelOrder  (Status (*operate) (iTree<T>*));
        //virtual ~iTree();
};

template <typename T>
iTree<T>* iTree<T>::root(){
    iTree<T>* _root = this ;
    if (this->parent()){
        _root = this->parent()->root();
    }
    return _root ;
}

template <typename T>
int iTree<T>::depth(){
    int _depth = 0 ;
    if (this->degree()){
        _depth = 1 ;
    }

    int max_child_depth = 0 ;
    for (int i = 0 ; i < this->degree() ; i ++){
        max_child_depth = std::max(
            max_child_depth ,
            this->child(i)->depth()
        );
    }

    _depth += max_child_depth ;
    return _depth;
}


/*
* 对于深度优先遍历
* 一个使用递归方法
* 一个使用stack方法
    * stack方法中
    * preOrder是 弹出->读取->压入child
    * postOrder是 
        * 压入root
        * 检测stack最上层元素能否压入child
        * 如果不行则弹出并读取，可以则继续压入child
        * 并且要检测是否压入过了 
*/
template <typename T>
Status iTree<T>::preOrder(
    Status (*operate) (iTree<T>*))
{
    if (not operate(this))
        return ERROR ;
    for (int i = 0 ; i < this->degree() ; i ++){
        if ( not
             this->child(i)->preOrder(operate))
        {
            return ERROR ;
        }
    }  
    return OK;
}

template <typename T>
Status iTree<T>::postOrder(
    Status (*operate) (iTree<T>*))
{
    std::stack<iTree<T>*>   nodes ;
    std::vector<iTree<T>*>  used_nodes;
    nodes.push(this);
    
    while(not nodes.empty()){
        iTree<T>* cur = nodes.top();
        
        /*
        * 无子节点，直接弹出
        */
        if (not cur->degree()){
            nodes.pop();
            if (not operate(cur))
                return ERROR ;
            used_nodes.push_back(cur);
            continue;
        }

        bool allChildUsed = false ;
        /*
        * 因为是从右往左压入
        * 及idx高的child先压入
        * 所以比较child(0)即可
        */
        for (iTree<T>* used_node : used_nodes){
            if (used_node == cur->child(0)){
                allChildUsed = true ;
            }
        }

        if (allChildUsed){
            nodes.pop();
            if (not operate(cur))
                return ERROR ;
            used_nodes.push_back(cur);
            continue;
        }else{
            for (int i = cur->degree() - 1 ; i >= 0 ; i --){
                nodes.push(cur->child(i));
            }
        }
        
    }

    return OK ;
}

template <typename T>
Status iTree<T>::levelOrder(
    Status (*operate) (iTree<T>*))
{
    std::queue<iTree<T>*> nodes ;

    nodes.emplace(this);
    while(not nodes.empty()){
        iTree<T>* cur = nodes.front();
        nodes.pop();

        if (not operate(cur))
            return ERROR ;
        
        for (int i = 0 ; i < cur->degree() ; i ++){
            nodes.emplace(cur->child(i));
        }
    }
    return OK ;
}

template <typename T>
bool iTree<T>::included(iTree<T>* child){
    bool _included = false ;

    if (this == child){
        _included = true ;
    };

    for (int i = 0 ; i < this->degree() ; i ++){
        if (
            this->child(i)->included(child)
        )
        {
            _included = true ;
        }
    }

    return _included ;
}

/*
// 无法为定义一个要用到其他纯虚函数的析构函数

// template <typename T>
// iTree<T>::~iTree(){
//     for (int i = 0 ; i < this->degree() ; i ++){
//         delete this->child(i);
//     }
//     //delete this;
//     // 不应当delete this , 否则析构函数会被无限调用
// }
*/
#endif
