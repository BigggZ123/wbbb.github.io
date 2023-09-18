/*
* 待调整
* 应当将BiTree也设置一种抽象类
* iBiTree,来定义类BiTree结构
* 如此，CompleteBiTree AVL等其他特殊BiTree结构才能在存储上有更大的灵活性
* 而类似于iTree与Tree，平凡的BiTree直接实现iBiTree中的基本接口即可
*/


#ifndef _I_BI_TREE_H
#define _I_BI_TREE_H

#include "../state.h"
#include "iTree.h"

template <typename T>
class iBiTree : public iTree<T>{
    /*
    * 为了适应BiTree的特殊子类
    * 此处将BiTree也提取出了一个不实际存储数据的抽象类
    * 代码冗余量有点大哦......
    */
    public:
        virtual iBiTree<T>* getLChild   () = 0 ;
        virtual iBiTree<T>* getRChild   () = 0;
        virtual Status      setLChild   (iBiTree<T>*) = 0 ;
        virtual Status      setRChild   (iBiTree<T>*) = 0 ;
    protected:
        T               _data ;
    protected:
        virtual bool        legalPos    (int pos) ;
        iTree<T>*           child       (int pos)   override;
        Status              erase       (int pos)   override;
        Status              addChild    (int pos , iTree<T>* child) override;
    public :
        T&                  data        ()          override;
        int                 degree      ()          override;
        iTree<T>*           parent      ()          override;
    public :
        virtual iTree<T>*   root      ()          override;
        virtual Status      inOrder     (Status (*operate) (iTree<T>*));
        //virtual Status  visitThis   (Status (*operate) (iTree<T>*));   
};


template <typename T>
inline
T& iBiTree<T>::data(){
    return this->_data;
}

template <typename T>
inline 
bool iBiTree<T>::legalPos(int pos){
    if (pos == 0 or pos == 1) return true;
    return false ;
}

template <typename T>
inline
iTree<T>* iBiTree<T>::child(int pos){
    if (not this->legalPos(pos)) return NULL ;
    if (pos == 0) return this->getLChild();
    if (pos == 1) return this->getRChild();
    return NULL ;
}

template <typename T>
int iBiTree<T>::degree(){
    int _degree = 0 ;
    if (this->getLChild()) _degree ++ ;
    if (this->getRChild()) _degree ++ ;
    return _degree;
}


template <typename T>
inline
Status iBiTree<T>::erase(int pos){
    if (not this->legalPos(pos)) return ERROR;
    if (pos == 0) this->setLChild(NULL) ;
    if (pos == 1) this->setRChild(NULL) ;
    return OK;
}

template <typename T>
inline
Status iBiTree<T>::addChild(int pos, iTree<T>* tree){
    if (not this->legalPos(pos)) return ERROR;
    
    //强制转型
    iBiTree<T>*child = (iBiTree<T>*)tree;
    if (pos == 0) this->setLChild(child) ;
    if (pos == 1) this->setRChild(child);
    return OK;
}

template <typename T>
inline 
iTree<T>* iBiTree<T>::parent(){
    return NULL ;
}

template <typename T>
inline
iTree<T>* iBiTree<T>::root(){
    return NULL ;
}


#include "VisitTree.h"
template <typename T>
Status iBiTree<T>::inOrder(
    Status (*operate) (iTree<T>*))
{
    //std::cout << "IN ORDER TRAVERSING..." << showTreeNode(this) << std::endl ;
    
    
    if (this->getLChild()){
        if (
            not
            this->getLChild()->inOrder(operate))
        {
            return ERROR;
        }
    }

    if (not operate(this)) return ERROR ;

    if (this->getRChild()){
        if (
            not 
            this->getRChild()->inOrder(operate))
        {
            return ERROR ;
        }
    }
    

    return OK ;
}

// // template <typename T>
// // Status iBiTree<T>::visitThis(
// //     Status (*operate)(iTree<T>*))
// // {
// //     operate(this);
// //     return OK ;
// // }
#endif