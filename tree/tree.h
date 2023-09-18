#ifndef _TREE_H
#define _TREE_H

#include "absTree.h"

template <typename T>
class node:public iTreeNode<T>{
    public :
        Status push(iTreeNode<T>* child) override{
            this->children.push_back(child);
            return OK ;
        }
        Status remove(int pos) override{
            if (pos < 0) return ERROR;
            if (pos >= this->children.size()) return ERROR ;
            
            this->children.erase(
                this->children.begin() + pos
                );
            return OK ;
        }
        Status degree() const override{
            return this->children.size() ;
        }
        Status clear(int pos) override{
            if (pos < 0) return ERROR;
            if (pos >= this->children.size()) return ERROR ;

            this->children[pos] = NULL ;
            return OK;
        }
};

template <typename T>
class tree : public iTree<T>{
};

#endif