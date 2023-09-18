#ifndef _BI_TREE_H
#define _BI_TREE_H

#include "iBiTree.h"
#include "../state.h"

template <typename T>
class BiTree : public iBiTree<T>{
    protected :
        T _data ;
        BiTree<T>* LChild ;
        BiTree<T>* RChild ;
    public :
        BiTree() ;
        BiTree(T data);
        T&          data        ()              override;
        iBiTree<T>* getLChild   ()              override;
        iBiTree<T>* getRChild   ()              override;
        Status      setLChild   (iBiTree<T>*)   override;
        Status      setRChild   (iBiTree<T>*)   override;
        iBiTree<T>* parent      ()              override;
};

/*
* 一个测试经常用的demo
* 直接放在头文件里面算了
*/
BiTree<char>* stdBiTreeDemo(){
    BiTree<char>*t = new BiTree<char> [7];
    for (int i =  0 ; i < 7 ; i ++){
        t[i].data() = 'A' + i ;
        //cout << t[i].data() ;
    }
    t[0].setLChild(&t[1]);
    t[0].setRChild(&t[2]);
    t[1].setLChild(&t[3]);
    t[1].setRChild(&t[4]);
    t[4].setLChild(&t[5]);
    t[4].setRChild(&t[6]);

    return t ;
}


template <typename T>
inline
iBiTree<T>* BiTree<T>::getLChild(){
    return this->LChild;
}

template <typename T>
inline
iBiTree<T>* BiTree<T>::getRChild(){
    return this->RChild;
}

template <typename T>
inline
iBiTree<T>* BiTree<T>::parent(){
    return NULL;
}

template <typename T>
inline
Status BiTree<T>::setLChild(iBiTree<T>* LChild){
    //std::cout << "setting..." << std::endl;
    this->LChild = (BiTree<T>*)LChild;
    //std::cout << "setted!" << std::endl;
    return OK;
}

template <typename T>
inline
Status BiTree<T>::setRChild(iBiTree<T>* RChild){
    this->RChild = (BiTree<T>*)RChild;
    return OK;
}

template <typename T>
inline
T& BiTree<T>::data(){
    return this->_data;
}

template <typename T>
inline
BiTree<T>::BiTree(){
    this->LChild = NULL;
    this->RChild = NULL;
}

template <typename T>
inline
BiTree<T>::BiTree(T data){
    this->_data = data;
    this->LChild = NULL;
    this->RChild = NULL;
}
#endif