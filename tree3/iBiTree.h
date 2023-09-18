#ifndef _I_BI_TREE_H
#define _I_BI_TREE_H

#include "../state.h"
#include <queue>

template <typename T>
class iBiTree;
template <typename T>
class iTreeOperate;


template <typename T>
class iBiTree{
    /*
    * 类似tree2文件中的iTree类
    * 不实际存储数据，而是通过方法的形式"访问"数据
    * 但tree3文件中，是以BiTree为最底层的存储结构
    */
    public :
        virtual T&          data        ()              = 0 ;
        virtual iBiTree<T>* getLChild   ()              = 0 ;
        virtual iBiTree<T>* getRChild   ()              = 0 ;
        virtual Status      setLChild   (iBiTree<T>*)   = 0 ;
        virtual Status      setRChild   (iBiTree<T>*)   = 0 ;
        virtual iBiTree<T>* parent      ()              = 0 ;
    public :
        virtual iBiTree<T>* root        ()      ;
        virtual int         depth       ()      ;
        virtual int         degree      ()      ;
        virtual bool        included    (iBiTree<T>* child)      ;
        virtual Status      preOrder    (iTreeOperate<T>* operate);
        virtual Status      inOrder     (iTreeOperate<T>* operate);
        virtual Status      postOrder   (iTreeOperate<T>* operate);
        virtual Status      levelOrder  (iTreeOperate<T>* operate);
};

template <typename T>
class iTreeOperate{
    /*
    * BiTree的辅助类
    * 提供更灵活的遍历操作
    * 参考testAutoTemplate.cpp中的方法
    */
    public :
        virtual Status operate      (iBiTree<T>* tat) = 0;
        
        Status operator() (iBiTree<T>*tat){
            return this->operate(tat);
        }
};

template <typename T>
iBiTree<T>* iBiTree<T>::root(){
    iBiTree<T>* _root = NULL;
    while (this->parent()){
        _root = this->parent() ;
    }
    return _root ;
}

template <typename T>
int iBiTree<T>::degree(){
    int _degree = 0 ;
    if (this->getLChild()) _degree ++ ;
    if (this->getRChild()) _degree ++ ;
    return _degree;
}

template <typename T>
int iBiTree<T>::depth(){

    if (not this->degree()){
        
        return 0 ;
    
    }else{
        int _depth = 1 ;

        if (not this->getLChild()){
            _depth += this->getRChild()->depth() ;
        }
        else 
        if (not this->getRChild()){
            _depth += this->getLChild()->depth() ;
        }
        else{
            _depth += std::max(
                this->getLChild()->depth() ,
                this->getRChild()->depth()
            );
        }

        return _depth;
    }
}

/*
* DFS的stack实现
* 请见tree2系列
* 这里图省事就没做

* 以后可以在子类中单独实现DFS试试

*/
template <typename T>
Status iBiTree<T>::preOrder(
    iTreeOperate<T>* operate)
{
    if (not operate) 
        return ERROR ;
    
    if (
        not
        operate->operate(this)
    ){
        return ERROR ;
    }

    if (this->getLChild()){
        if (
            not 
            this->getLChild()->preOrder(operate)
        ){
            return ERROR ;
        }
    }

    if (this->getRChild()){
        if (
            not 
            this->getRChild()->preOrder(operate)
        ){
            return ERROR ;
        }
    }

    return OK ;
}

template <typename T>
Status iBiTree<T>::inOrder(
    iTreeOperate<T> *operate)
{
    if (not operate) 
        return ERROR ;

    if (this->getLChild()){
        if (
            not 
            this->getLChild()->inOrder(operate)
        ){
            return ERROR ;
        }
    }
    
    if (
        not
        operate->operate(this)
    ){
        return ERROR ;
    }

    if (this->getRChild()){
        if (
            not 
            this->getRChild()->inOrder(operate)
        ){
            return ERROR ;
        }
    }

    return OK ;
}

template <typename T>
Status iBiTree<T>::postOrder(
    iTreeOperate<T>* operate)
{
    if (not operate) 
        return ERROR ;

    if (this->getLChild()){
        if (
            not 
            this->getLChild()->inOrder(operate)
        ){
            return ERROR ;
        }
    }

    if (this->getRChild()){
        if (
            not 
            this->getRChild()->inOrder(operate)
        ){
            return ERROR ;
        }
    }

    if (
        not
        operate->operate(this)
    ){
        return ERROR ;
    }

    return OK ;
}

template <typename T>
Status iBiTree<T>::levelOrder(
    iTreeOperate<T>* operate)
{
    if (not operate) return ERROR ;

    std::queue<iBiTree<T>*> nodes ;
    
    nodes.push(this);

    while (not nodes.empty())
    {
        iBiTree<T>* node = nodes.front();
        nodes.pop();

        if (not operate->operate(node))
            return ERROR;

        if (node->getLChild())
            nodes.push(node->getLChild());

        if (node->getRChild())
            nodes.push(node->getRChild());
    }
    return OK ;
}


template <typename T>
class BiTreeNotEqal : public iTreeOperate<T>{
    /*
    * included的辅助类
    */
    protected:
        iBiTree<T>* base ;
    public:
        BiTreeNotEqal(iBiTree<T>* base){
            this->base = base ;
        }
        Status operate(iBiTree<T>* tat) override{
            if (this->base == tat) 
                return false ;
            return true;
        }
};

template <typename T>
bool iBiTree<T>::included(iBiTree<T>* child){
    /*
    * 终于实现我的
    *   使用traverse为载体
    *   进行各种组合操作
    * 的宏图大愿啦
    * <(^o^)7
    */

   /*
   * 使用双重否定的形式
   */
    if (
        not
        this->preOrder(
            new BiTreeNotEqal<T>(child)
        )
    ){
        return true ;
    }else{
        return false ;
    }

}

void __demo__(){
    /*
    * 主要对traverse的使用
    * 见included函数的实现就是一个很好的例子
    */
}

#endif