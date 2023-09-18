#ifndef _I_TREE_H
#define _I_TREE_H

#include "BiTree.h"

template <typename T>
class iTree{
    /*
    * TreeNode所携带数据的访问与修改
    */
    public :
        virtual T&          data        ()          = 0 ;
        virtual iTree*      child       (int pos)   = 0 ;
        virtual int         degree      ()          = 0 ;
        virtual Status      erase       (int pos)   = 0 ;
        virtual Status      addChild    (int pos , iTree<T>* child)   = 0 ;
        virtual iTree*      parent      ()          = 0 ;
    /*
    * 实际Tree层面的操作
    */
    public :
        virtual iTree*      root        ()        ;
        virtual int         depth       ()        ;
        virtual bool        included    (iTree<T>* child);
        virtual Status      preOrder    (Status (*operate) (iTree<T>*));
        virtual Status      postOrder   (Status (*operate) (iTree<T>*));
        virtual Status      levelOrder  (Status (*operate) (iTree<T>*));
        //virtual ~iTree();
};


#endif