#ifndef _I_BI_TREE_H
#define _I_BI_TREE_H

#include "iTree.h"
template <typename T>
class iBiTree : public iTree<T>{
    /*
    * TreeNode所携带数据的访问与修改
    */
    public :
        virtual T&          data        ()              = 0 ;
        virtual iTree<T>*   parent      ()              = 0 ;
    protected:
        virtual iTree*      child       (int pos)       = 0 ;
        virtual Status      erase       (int pos)       = 0 ;
        virtual Status      addChild    (int pos , iTree<T>* child)   = 0 ;
    public :
        virtual iBiTree<T>* getLChild   ()              = 0 ;
        virtual iBiTree<T>* getRChild   ()              = 0 ;
        virtual Status      setLChild   (iBiTree<T>*)   = 0 ;
        virtual Status      setRChild   (iBiTree<T>*)   = 0 ;
    public :
        virtual iTree<T>*   root        ()      ;
        virtual int         depth       ()      ;
        virtual int         degree      ()      ;
        //virtual bool        included    (iBiTree<T>* child)      ;
        virtual Status      preOrder    (iTreeOperate<T>* operate);
        virtual Status      inOrder     (iTreeOperate<T>* operate);
        virtual Status      postOrder   (iTreeOperate<T>* operate);
        virtual Status      levelOrder  (iTreeOperate<T>* operate);
};

#endif