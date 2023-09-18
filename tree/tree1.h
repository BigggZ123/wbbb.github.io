#ifndef _TREE_H
#define _TREE_H

/*
//为了节省内存空间
//此处的Tree class 是对整棵树的抽象
//而之中子树并不是一颗完整的tree class, 而是 treenode class
//即有些层面的操作是Tree级别的，而node级别没有
    //这也导致了Tree看上去比较分离
//通过设置工厂函数，可以将node包装成一棵完整的tree
*/

#include "../state.h"
#include <iostream>
#include <vector>
#include <queue>        //层序遍历
#include <algorithm>
using namespace std;

/*
DEFINITION
*/
template <typename T , class TreeNode>
class Tree{
    public :
        TreeNode*       _root;
        /*
        //因为封装不完全，能够直接操作node，所以需要depth时候现计算
        // int             _depth;
        */
    protected:
    public :
        Status          originPreOrder  (TreeNode* current,Status (*visit)(TreeNode*));
        Status          originPostOrder (TreeNode* current,Status (*visit)(TreeNode*));
        Status          originLevelOrder(TreeNode* current,Status (*visit)(TreeNode*)); 
        int             nodeDepth       (TreeNode* current); 
    public :
        Tree();
        Tree(TreeNode& root);
        ~Tree();
        Status          init            (T rootData);
        Status          init            (TreeNode& root);
        bool            empty           ()                  const;
        bool            included        (TreeNode& node)    const;
        TreeNode*       root            ()                                      {return _root;}
        int             depth           ();
        TreeNode*       parent          (TreeNode& child);
        Status          insert          (TreeNode& child);
        Status          insert          (T childData);
        Status          preOrder        (Status (*visit)(TreeNode*));
        Status          postOrder       (Status (*visit)(TreeNode*));  
        Status          levelOrder      (Status (*visit)(TreeNode*));
};

template <typename T>
class TreeNode{
    public : 
        T                   data ;
        vector<TreeNode*>   children;
    public:
        int         degree      ()                  const       {return children.size();};
        Status      push        (TreeNode&);
        Status      insert      (int , TreeNode&);
        Status      remove      (int pos);
};

template <typename T>
using tree = Tree<T , TreeNode<T> >;


/*
IMPLEMENTATION
*/

template <typename T>
Status TreeNode<T>::push(TreeNode& child){
    this->children.push_back(&child);
    return OK;
}

template <typename T>
inline 
Status TreeNode<T>::remove(int pos){
    if (pos < 0) return ERROR;
    if (pos > this->children.size()) return ERROR ;

    this->children.erase(
        this->children.begin() + pos
    );
    return OK ;
}

template <typename T , class node>
Tree<T,node>::Tree():
    _root(NULL)
{
    ;
}

template <typename T , class node>
Tree<T,node>::Tree(node& root):
    _root(&root)
{

}

template <typename T , class node>
Tree<T,node>::~Tree()
{

}

template <typename T , class node>
Status Tree<T,node>::init( T data ){
    if (this->_root) return ERROR ;

    this->_root = new node ;
    this->_root->data = data ;
    return OK ;
}

template <typename T , class node>
inline 
Status Tree<T,node>::init(node& root){
    if (this->_root) return ERROR ;
    this->_root = &root ;
    return OK ;
}

template <typename T , class node>
inline 
bool Tree<T,node>::empty()  const{
    return ((bool) this->_root);
}


#ifndef _DIFFERENT
#define _DIFFERENT
struct DIFFERENT{
    template <typename T>
    Status operator() (const T& x ,const T& y){
        return (
            (Status) (x != y)
        );
    };
};
DIFFERENT Different;
#endif
#ifndef _EQUAL
#define _EQUAL
struct EQUAL{
    public:
        template <typename T>
        Status operator() (const T& x ,const T& y){
            return ((int)(x == y));
        }
};
EQUAL Equal  ;
#endif

template <class node>
Status differ(node* x , node* y){
    return (
        (int)( 
            x!= y )
    );
}

template <typename T , class node>
bool Tree<T,node>::
included( node& child ) const{
    node* childPtr = &child ;
    
    /*
    //类型出错
    return(
        not (
            (bool)(
                this->preOrder(this->_root,Different)
            )
        )
    );
    */

   //不是层序遍历好用
   //就是懒得写递归了...
    queue<node*> line ;
    node* elem ;

    line.emplace(this->_root);
    while(!line.empty()){
        elem = line.front();
        line.pop();

        if (childPtr == elem){
            return true;
        }

        for (int i = 0 ; i < elem->children.size() ; i ++) {
            line.push(elem->children[i]);
        }
    }
    return false ;
}

template <typename T , class node>
int Tree<T , node >::nodeDepth(node* current){
    int depth = 1 ;//当前深度为1
    
    int childDepth = 0 ;
    for (int i = 0 ; i < current->children.size() ; i ++){
        int curDepth = this->nodeDepth(
            current->children[i]
        );
        childDepth = max(curDepth,childDepth);
    }
    
    return (depth + childDepth);
}

template <typename T , class node>
inline
int Tree<T,node>::depth(){
    return (
        this->nodeDepth(
            this->_root
        )
    );
}

template <typename T , class node>
Status Tree<T,node>::originPreOrder(
    node* current , Status (*visit)(node*))
{
    if (not visit(current)) return ERROR ;

    for (int i = 0 ; i < current->children.size() ; i++){
        if ( 
            not this->originPreOrder(
                        current->children[i],
                        visit))
        {
            return ERROR ;
        }
    }
    return OK ;
}

template <typename T , class node>
Status Tree<T,node>::originPostOrder(
    node* current , Status(*visit)(node*))
{
    for (int i = 0 ; i < current->children.size() ; i++){
        if ( 
            not this->originPostOrder(
                        current->children[i],
                        visit))
        {
            return ERROR ;
        }
    }

    if (not visit(current)) return ERROR ;

    return OK ;
}

template <typename T , class node >
Status Tree<T,node>::originLevelOrder(
     node* current , Status(*visit)(node*))
{
    queue<node*> line ;
    node* elem ;

    line.emplace(current);
    while(!line.empty()) {
        elem = line.front();
        line.pop();

        if (not visit(elem)) return ERROR ;

        for (int i = 0 ; i < elem->children.size() ; i ++) {
            line.push(elem->children[i]);
        }
    }
    return OK ;
}

template <typename T , class node >
inline
Status Tree<T,node>::preOrder(
    Status (*visit)(node*))
{
    return (
        this->originPreOrder(
            this->_root,
            visit
        )
    );
}

template <typename T , class node>
inline 
Status Tree<T,node>::postOrder(
    Status (*visit)(node*))
{
    return (
        this->originPostOrder(
            this->_root,
            visit
        )
    );
}

template <typename T , class node>
inline 
Status Tree<T,node>::levelOrder(
    Status (*visit)(node*))
{
    return (
        this->originLevelOrder(
            this->_root,
            visit
        )
    );
}

#endif