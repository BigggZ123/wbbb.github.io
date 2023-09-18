#ifndef _TREE_H
#define _TREE_H

#include "iTree.h"
#include "../state.h"
#include <vector>
using namespace std ;

template <typename T>
class Tree : public iTree<T>
{
    protected:
        T               _data ;
        Tree*           _parent;
        vector<Tree*>   children;  
    public :
        Tree();
        Tree(Tree& parent);
        T&          data    ()                          override    ;
        iTree<T>*   child   (int pos)                   override    ;
        int         degree  ()                          override    ;
        iTree<T>*   parent  ()                          override    ;
        Status      erase   (int pos)                   override    ;
        Status      addChild(int pos , iTree<T>* iChild)  override    ;
};

template <typename T>
Tree<T>::Tree(){
    this->_parent = NULL;
}

template <typename T>
Tree<T>::Tree(Tree<T>& parent){
    this->_parent = parent ;
}

template <typename T>
inline 
T& Tree<T>::data(){
    return this->_data;
}

template <typename T>
inline
int Tree<T>::degree(){
    return this->children.size();
}

template <typename T>
inline
iTree<T>* Tree<T>::child(int pos){
    if (pos < 0) return NULL;
    if (pos > this->degree()) return NULL;

    return this->children[pos] ;
}

template <typename T>
inline 
iTree<T>* Tree<T>::parent(){
    return this->_parent;
}

template <typename T>
Status Tree<T>::erase(int pos){
    if (pos < 0) return ERROR ;
    if (pos > this->degree()) return ERROR ;

    this->children.erase(
            this->children.begin() + pos 
        );
    return OK ;
}

/*
* 注:删除所有元素的方法：
* while(degree() != 0){
    erase(0);
}
*/

template <typename T>
Status Tree<T>::addChild(int pos , iTree<T>* iChild){
    if (pos < 0) return ERROR ;
    if (pos > this->degree()) return ERROR ;

    /*
    // * 此处使用强制转型而非dynamic_cast
    // * 因为dynamic_cast转换后无法访问Tree类特有的成员
    */
    // Tree<T>* child = dynamic_cast<Tree<T>*>(iChild);
    Tree<T>* child = (Tree<T>*) iChild;
    child->_parent = this ;
    this->children.insert(
        this->children.begin() + pos , 
        child
    );

    return OK ;
}


#endif
