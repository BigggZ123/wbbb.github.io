#ifndef _BI_TREE_H
#define _BI_TREE_H

#include "limTree.h"

#ifndef _BI_TREE_NODE_H
#define _BI_TREE_NODE_H
template <typename T>
class BiTreeNode : public LimTreeNode<T,2>{
    /*
    // 逻辑上BiTreeNode确实继承与LiTreeNode
    // 然而貌似每个方法都要重写一遍......

    //这也许是设计上的错误导致的
    //BiTreeNode本不应该继承自如此的LIMTreeNode类，因为存取规则不同
    */
    public :
        BiTreeNode();
        bool typeCheck(iTreeNode<T>*) override;
        Status push (iTreeNode<T>*) override;
        Status remove(int pos) override;
};

template <typename T>
BiTreeNode<T>::BiTreeNode(){
    //cout << this->maxDegree() << endl ;
    LimTreeNode<T,2>::push(NULL);
    LimTreeNode<T,2>::push(NULL);
    //预存两个节点以占位，后续修改push操作
    //因为BiTreeNode存在L或Rchild为空的情况
}

template <typename T>
inline
bool BiTreeNode<T>::typeCheck(iTreeNode<T>* node){
    return (
        dynamic_cast<BiTreeNode<T>*>
        (node)
    );
}

template <typename T>
Status BiTreeNode<T>::push(iTreeNode<T>* child){
    if (not this->typeCheck(child)) return ERROR ;
    
    //忽视NULL,并在NULL基础上进行的push
    
    if (not this->children[0]){
        this->children[0] = child ;
        return OK ;
    }
    if (not this->children[1]){
        this->children[1] = child ;
        return OK ;
    }

    return ERROR ;
}

template <typename T>
Status BiTreeNode<T>::remove(int pos){
    if (pos < 0 or pos >= 2) return ERROR ;
    else {
        this->children[pos] = NULL ;
        return OK ;
    }
}
#endif
/*
    用于检测typeCheck功能能否拒绝基类指针
    成功
    
template <typename T>
class CTreeNode : public BiTreeNode<T>{
    public :
        bool typeCheck(iTreeNode<T>* child) override{
            return (
                dynamic_cast<
                    CTreeNode*>
                    (child)
            );
        } 
};

*/

template <typename T>
class BiTree : public iTree<T>{
    protected:
        virtual bool        nodeCheck           (iTreeNode<T>* node);
        virtual Status      originInOrder       (iTreeNode<T>*current , Status(*visit)(iTreeNode<T>*));
    public :
        // Status              preOrder            (Status (*visit) (iTreeNode<T>*)) override;
        // Status              postOrder           (Status (*visit) (iTreeNode<T>*)) override;
        virtual Status      inOrder             (Status (*visit) (iTreeNode<T>*) = showNodeData);
        BiTree();
        BiTree(iTreeNode<T>*);
};

template <typename T>
inline
BiTree<T>::BiTree(){
    BiTree(new BiTreeNode<T>);
}

template <typename T>
BiTree<T>::BiTree(iTreeNode<T>* root){
    if (not this->nodeCheck(root)){
        std::cerr << "A mismatched node has pushed in the BINARY tree" << endl ;
        throw "A mismatched node has pushed in the BINARY tree";
    }else{
        this->_root = root ;
    }
}

template <typename T>
inline 
bool BiTree<T>::nodeCheck(iTreeNode<T>* node){
    static BiTreeNode<T> inspector ;
    cout << "Node type CHECKING ..."<< endl ;
    return (inspector.typeCheck(node));
}

template <typename T>
Status BiTree<T>::originInOrder(
    iTreeNode<T>* current , Status (*visit)(iTreeNode<T>*))
{   
    //if (not nodeCheck(current)) return ERROR ;
        //仅在InOrder的时候校验就行了,不然开销太大了
        //且BiTreeNode自己就有检测机制
    if(not current) return ERROR ;
    if (not visit) return ERROR ;

    if  (this->originInOrder( current->children[0] , visit)){
        if (visit(current)){
            if (this->originInOrder(current->children[1] , visit)){
                return OK ;
            }
        }
    }
    return ERROR ;
}

template <typename T>
inline 
Status BiTree<T>::inOrder(Status (*visit)(iTreeNode<T>*)){
    if (not this->nodeCheck(this->_root)) return ERROR ;
    
    return (
        this->originInOrder(
            this->_root ,
            visit
        )
    );
}



#endif