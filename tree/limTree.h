#ifndef _LIM_TREE_H
#define _LIM_TREE_H
#include "absTree.h"
template <typename T , int MaxSize>
class LimTreeNode : public iTreeNode<T>{
    protected :
        int maxSize;
    public:
        LimTreeNode() ;

        virtual bool typeCheck (iTreeNode<T>*);

        int degree() const override ;

        int maxDegree () const {return maxSize;}    

        Status push(iTreeNode<T>* child) override;

        Status remove(int pos) override;

        Status clear (int pos) override ;
};

template <typename T , int MaxSize>
LimTreeNode<T,MaxSize>::LimTreeNode():
    maxSize(MaxSize)
{
    for (int i = 0 ; i < MaxSize ; i ++){
        this->children.push_back(NULL);
    }
}

template <typename T , int MaxSize>
inline
bool LimTreeNode<T, MaxSize>::typeCheck(iTreeNode<T>* child){
    return (
        dynamic_cast<
            LimTreeNode< T , MaxSize >* >
            (child)
    );
}


template <typename T , int MaxSize>
int LimTreeNode<T,MaxSize>::degree() const{
    int child_cnt = 0 ;
    for (int i = 0 ; i < this->maxSize ; i ++){
        if (this->children[i])  
            child_cnt ++ ;
    }
    return child_cnt ;
}

template <typename T , int maxSize>
Status LimTreeNode<T , maxSize>::
push(iTreeNode<T>* child){
    if (not child){
        this->children.push_back(NULL);
        return OK ;
    }
    //要允许插入NULL指针，二叉树才有搞头

    if (not this->typeCheck(child)){
        return ERROR ;//确保本节点类型正确
    }
    else
    if (this->degree() >= this->maxSize){
        return ERROR ;
    }
    else{
        this->children.push_back(child);
        return OK;
    }
}

template <typename T , int maxSize>
Status LimTreeNode<T , maxSize>::
remove(int pos){
    if (pos < 0) return ERROR;
    if (pos >= this->children.size()) return ERROR ;

    this->children.erase(
        this->children.begin() + pos
        );
    return OK ;
}

template <typename T , int maxSize>
Status LimTreeNode<T,maxSize>::clear(int pos){
    if (pos < 0 or pos >= this->maxDegree()) return ERROR ;
    
    else{
        this->children[pos] = NULL ;
        return OK ; 
    }
}
/*
//检测功能开发失败
    //当前存在内存溢出
    //即使内存不溢出，如此操作也会导致大量的内存与时间开销
template <typename T , int MaxSize>
Status LimTreeNode<T,MaxSize>::
typeCheck(iTreeNode<T>* node){
    //确保类型为LIMTreeNode类型
        //通过测试Node的push,查看Node是否有MaxDegree已经MaxDegree是否相同
    if (not node) return INFEASIBEL;

    bool sameNodeType = true ;

    int curSize = node->degree();
    if (curSize > this->maxDegree()){
        sameNodeType = false ;
    }
    else 
    if (curSize == this->maxDegree()){
        if (node->push(new LimTreeNode<T,MaxSize>)){
            node->remove(this->maxDegree()+1);
            sameNodeType = false ;
        }
    }
    else{
        for (int i = curSize ; i < this->maxDegree() ; i++){
            if (not node->push(new LimTreeNode<T,MaxSize>)){
                sameNodeType = false ;//说明degree更小
            }
        }
        if (sameNodeType){
            //说明能容纳对应的maxDegree
            if (node->push(new LimTreeNode<T,MaxSize>)){
                sameNodeType = false ;
            }
        }
        
        //释放测试用内存
        for (
            int i = curSize;
            i < this->maxDegree() + (
                (sameNodeType)?0:1);
            i++)
        {
            node->remove(node->degree() - 1);
        }
    }
    
    if (sameNodeType) return OK ;
    else return ERROR ;
}
*/

#endif