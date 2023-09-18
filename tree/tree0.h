#ifndef _TREE_H
#define _TREE_H

#include "../state.h"
#include <iostream>
#include <vector>
using namespace std ;

template <typename T>
class Tree{
/*
    使用-1来表示参数子树个数为任意
*/
    public :
        T               data ;
        Tree*           _parent ;
        vector<Tree*>   children;
        int             _max_size;
        int             _size;
        int             _depth;
    public :
        Tree();
        Tree(Tree& _parent);
        Tree(int size);
        Tree(int size , Tree& _parent);
        int             depth       ()          const           {return _depth;}
        int             size        ()          const           {return _size;}
        Tree&           parent      ();
        Status          insert      (Tree& child);
        Tree&           operator[]  (int pos);
        Tree&           sibling     (int pos);
        Status          preOrder    (Status (*visit)(Tree*));
        Status          postOrder   (Status (*visit)(Tree*));
        //void            show            ()          {cout << "Hello world" << endl;};
};
/*
//调用时候有bug
template <typename T>
Status connect(Tree<T>* parent , Tree<T>* child){
    if (not parent) return ERROR ;
    if (not child) return ERROR ;

    child->parent() = parent ;
    parent->children.push_back(child);
    return OK ;
}
*/


template <typename T>
Tree<T>::Tree():
    _max_size(-1) , _parent(NULL) , _depth(0),_size(0)
{
    //cout << "base constructor" << endl ;
    ;
}

template <typename T>
Tree<T>::Tree(Tree& _parent):
    _max_size(-1) , _parent(&_parent),_depth(0),_size(0)
{
    //cout << "constructor with parent" << endl ;
    ;
}

template <typename T>
Tree<T>::Tree(int maxSize):
    _max_size(maxSize) , _parent(NULL),_depth(0),_size(0)
{
    //cout << "constructor with size" << endl ;
    ;
}

template <typename T>
Tree<T>::Tree(int size , Tree& _parent):
    _max_size(size),_parent(&_parent) , _depth(0),_size(0)
{
    //cout << "constructor with size and parent" << endl ;
}


template <typename T>
inline 
Tree<T>& Tree<T>::parent(){
    if (not this->_parent) throw "No parent node" ;
    return *(this->_parent) ;
}

template <typename T>
Status Tree<T>::insert(Tree& child){
    if (this->children.size() >= this->_max_size){
        return false ;
    }
    this->children.push_back(&child);
    this->_size ++ ;
    return OK ;
}

template <typename T>
Status Tree<T>::preOrder(
    Status (*visit) (Tree*))
{
    
}

/*
//无法自动推断
template <typename T>
int depth(Tree<T> t){
    return t.depth() ;
}
*/

#endif