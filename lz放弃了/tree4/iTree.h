#ifndef _I_TREE_H
#define _I_TREE_H

#include "../state.h"

template <typename T>
class iTree ;

template <typename T>
class iTreeOperate;

template <typename T>
class iTree{
    /*
    * 为了适配BiTree相关操作，很多地方需要加入判断child是否为NULL的步骤
    * 由于degree逻辑的不同
    * 很多基于degree的操作在BiTree中都必须重载
    * 或者得修改child的访问逻辑
    * 总之感觉就是在这一点上造成了有限树和无限树的割裂
    * 
    * 但也可以将BiTree的degree恒定的设置为2
    * 
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
        //virtual bool        included    (iTree<T>* child);
        virtual Status      preOrder    (iTreeOperate<T>* operate);
        virtual Status      postOrder   (iTreeOperate<T>* operate);
        virtual Status      levelOrder  (iTreeOperate<T>* operate);
        //virtual ~iTree();
};

template <typename T>
class iTreeOperate{
    public :
        virtual Status operate (iTree<T>* tat) = 0 ;
};

template <typename T>
iTree<T>* iTree<T>::root(){
    iTree<T>* _root = this ;
    if (this->parent()){
        _root = this->parent()->root();
    }
    return _root ;
}

template <typename T>
int iTree<T>::depth(){
    int _depth = 0 ;
    if (this->degree()){
        _depth = 1 ;
    }

    int max_child_depth = 0 ;
    for (int i = 0 ; i < this->degree() ; i ++){
        if (this->child(i)){
            max_child_depth = std::max(
                max_child_depth ,
                this->child(i)->depth()
            );
        }
    }

    _depth += max_child_depth ;
    return _depth;
}


#endif