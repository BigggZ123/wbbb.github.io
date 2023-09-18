#ifndef _BI_TREE_H
#define _BI_TREE_H
#include "iBiTree.h"

template <typename T>
class BiTree : public iBiTree<T>{
    protected:
        BiTree<T>*  _LChild ;
        BiTree<T>*  _RChild ;
    public :
        BiTree<T>* getLChild() override{
            return this->_LChild;
        }
        BiTree<T>* getRChild() override{
            return this->_RChild;
        }
        Status setLChild(iBiTree<T>* LChild) override{
            this->_LChild = (BiTree<T>*) LChild;
            return OK ;
        }
        Status setRChild(iBiTree<T>* RChild) override{
            this->_RChild = (BiTree<T>*) RChild;
            return OK ;
        }
};

#endif