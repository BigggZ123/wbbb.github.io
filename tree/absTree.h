#ifndef _ABS_TREE_H
#define _ABS_TREE_H

#include <iostream>
#include <vector>
#include <queue>
#include "../state.h"
using namespace std ;

#ifndef _I_TREE_NODE_H
#define _I_TREE_NODE_H
template <typename T>
class iTreeNode{
    /*
    感觉对于iTree而言，iTreeNode这一个接口实际上设计大了
    此接口不应当实际存储数据
    */
    public :
        T data ;
        iTreeNode*            parent;
        vector<iTreeNode<T>*> children;
    public :
    /*
    // 写到BiTreeNode时候才明确，push就应当为push_back
    // 而访问、修改应当直接使用children[i]来实现

    // remove也应当为删去整个节点
    // 如此都是为了适配无限大小与有限大小做出的调节

    // 之前对于存储的child为NULL时候的逻辑十分的不明确

    //这样也会导致degree的非常的不明确,因为在limit模式下的node上来就需要填充至degree = full
    //或者将degree的逻辑定义为非空指针域
    */

   /*
//    实际上，对于iTree而言，依赖注入的iTreeNode只需要degree一个函数就可以了
//    然而为了后续能够批量化的修改节点本身(比如交互式的创建Tree)
//    才开放了push、degree与clear接口
//    以后可以酌情关闭这些接口
   */
        virtual Status      push        (iTreeNode<T>*child)        = 0;
        virtual int         degree      ()              const       = 0  ;
        virtual Status      remove      (int pos)                   = 0 ;
        virtual Status      clear       (int pos)                   = 0 ;
};
/*
// 感觉对于iTree而言，iTreeNode这一个接口实际上设计大了
// 此接口不应当实际存储数据
//可能的精简版接口：
template <typename T>
class iTreeNode{
    public :
        virtual iTreeNode*  operator[]  (int pos)               = 0 ;
        virtual iTreeNode*  parent      ()                      = 0 ;
        virtual int         degree      ()              const   = 0 ;
};

*/

template <typename T>
Status showNodeData(iTreeNode<T>* node){
    if (not node) return OK ;

    std::cout << node->data << std::endl ;
    return OK ;
}

#endif

#ifndef _I_TREE_H
#define _I_TREE_H
template <typename T>
class iTree{
    typedef iTreeNode<T> node ;
    public :
        iTreeNode<T>*       _root ;
    protected:
        virtual Status      originPreOrder  (node* current , Status (*visit) (node*));
        virtual Status      originPostOrder (node* current , Status (*visit) (node*));
        virtual Status      originLevelOrder(node* current , Status (*visit) (node*));
        virtual int         nodeDepth       (node*);
    public :
        iTree();
        iTree(node*root);
        ~iTree();
        virtual Status      init            (node* root);
        node*               root            ()                  const       {return _root;};
        bool                empty           ()                  const;
        bool                included        (node* node);  
        virtual int         depth           ();
        virtual Status      preOrder        (Status (*visit)(node*) = showNodeData);
        virtual Status      postOrder       (Status (*visit)(node*) = showNodeData);
        virtual Status      levelOrder      (Status (*visit)(node*) = showNodeData);
};

/*
IMPLEMENTATION
*/


template <typename T>
iTree<T>::iTree():
    _root(NULL)
{
    ;
}

template <typename T>
iTree<T>::iTree(iTreeNode<T>* root):
    _root(&root)
{
    ;
}

template <typename T>
iTree<T>::~iTree(){
    ;
}

template <typename T>
inline
Status iTree<T>::init(iTreeNode<T> *root){
    if (not root) return ERROR ;

    this->_root = root ;
    return OK ;
}

template <typename T>
inline 
bool iTree<T>::empty() const{
    return (
        (bool) this->_root 
    );
}

template <typename T>
int iTree<T>::nodeDepth(node* current){
    if (not current) return 0 ;

    int depth = 1 ;

    int childDepth = 0 ;
    for (int i = 0 ; i < current->degree() ; i ++){
        int curDepth = this->nodeDepth(
            current->children[i]
        );
        childDepth = max(curDepth , childDepth);
    }
    
    depth += childDepth;
    return depth ;
}

template <typename T>
inline 
int iTree<T>::depth(){
    return (
        this->nodeDepth(
            this->_root
        )
    );
}

template <typename T>
Status iTree<T>::originPreOrder(
    node*current , Status (*visit)(node*))
{
    /*
    允许current为null，看visit怎么处理即可
    */
    if (not visit(current))
        return ERROR ;

    for (int i = 0 ; i < current->degree() ; i ++){
        if (not this->originPreOrder(
                        current->children[i],
                        visit))
        {
            return ERROR ;
        }
    }
    return OK ;
}

template <typename T>
inline 
Status iTree<T>::preOrder(Status (*visit)(node*))
{
    return (
        this->originPreOrder(
            this->_root ,
            visit
        )
    );
}

template <typename T>
Status iTree<T>::originPostOrder(
    node* currnet , Status (*visit)(node*))
{
    /*
    允许current为null，看visit怎么处理即可
    */
    for (int i = 0 ; i < currnet->degree() ; i ++){
        if (not this->originPostOrder(
            currnet->children[i],
            visit))
        {
            return ERROR ;
        }
    }
    
    if (not visit(currnet)) return ERROR;

    return OK ;
}

template <typename T>
inline 
Status iTree<T>::postOrder(Status (*visit)(node*)){
    return (
        this->originPostOrder(
            this->_root,
            visit
        )
    );
}

template <typename T>
Status iTree<T>::originLevelOrder(
    node* current , Status(*visit)(node*))
{
    queue<node*> line ;
    node* elem ;

    line.emplace(current);
    while(!line.empty()) {
        elem = line.front();
        line.pop();

        if (not visit(elem)) return ERROR ;

        for (int i = 0 ; i < elem->degree() ; i ++) {
            line.push(elem->children[i]);
        }
    }
    return OK ;
}

template <typename T>
inline 
Status iTree<T>::levelOrder(Status (*visit)(node*)){
    return (
        this->originLevelOrder(
            this->_root,
            visit
        )
    );
}

#endif

#endif