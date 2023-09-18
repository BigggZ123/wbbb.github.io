/*
* BiTree修改前的源码
*/

/*
* 待调整
* 应当将BiTree也设置一种抽象类
* iBiTree,来定义类BiTree结构
* 如此，CompleteBiTree AVL等其他特殊BiTree结构才能在存储上有更大的灵活性
* 而类似于iTree与Tree，平凡的BiTree直接实现iBiTree中的基本接口即可
*/


// #ifndef _BI_TREE_H
// #define _BI_TREE_H

// #include "../state.h"
// #include "iTree.h"

// template <typename T>
// class BiTree : public iTree<T>{
//     /*
//     * BiTree 是没爹妈的东西
//     */
//     public:
//         BiTree<T>*       LChild ;
//         BiTree<T>*       RChild ;
//     protected:
//         T               _data ;
//     protected:
//         bool            legalPos    (int pos) ;
//     public :
//         T&              data        ()          override;
//         iTree<T>*       child       (int pos)   override;
//         int             degree      ()          override;
//         Status          erase       (int pos)   override;
//         Status          addChild    (int pos , iTree<T>* child) override;
//         iTree<T>*       parent      ()          override;
//     public :
//         BiTree();
//         BiTree(T data);
//         virtual iTree<T>* root      ()          override;
//         virtual Status  inOrder     (Status (*operate) (iTree<T>*));
//         //virtual Status  visitThis   (Status (*operate) (iTree<T>*));   
// };

// template<typename T>
// BiTree<T>::BiTree(){
//     this->LChild = NULL ;
//     this->RChild = NULL ;
// }

// template <typename T>
// BiTree<T>::BiTree(T data){
//     this->LChild = NULL ;
//     this->RChild = NULL ;
//     this->_data = data ;
// }

// template <typename T>
// inline
// T& BiTree<T>::data(){
//     return this->_data;
// }

// template <typename T>
// inline 
// bool BiTree<T>::legalPos(int pos){
//     if (pos == 0 or pos == 1) return true;
//     return false ;
// }

// template <typename T>
// inline
// iTree<T>* BiTree<T>::child(int pos){
//     if (not this->legalPos(pos)) return NULL ;
//     if (pos == 0) return this->LChild;
//     if (pos == 1) return this->RChild;
//     return NULL ;
// }

// template <typename T>
// int BiTree<T>::degree(){
//     int _degree = 0 ;
//     if (this->LChild) _degree ++ ;
//     if (this->RChild) _degree ++ ;
//     return _degree;
// }


// template <typename T>
// inline
// Status BiTree<T>::erase(int pos){
//     if (not this->legalPos(pos)) return ERROR;
//     if (pos == 0) this->LChild = NULL ;
//     if (pos == 1) this->RChild = NULL ;
//     return OK;
// }

// template <typename T>
// inline
// Status BiTree<T>::addChild(int pos, iTree<T>* tree){
//     if (not this->legalPos(pos)) return ERROR;
    
//     //强制转型
//     BiTree<T>*child = (BiTree<T>*)tree;
//     if (pos == 0) this->LChild = child ;
//     if (pos == 1) this->RChild = child;
//     return OK;
// }

// template <typename T>
// inline 
// iTree<T>* BiTree<T>::parent(){
//     return NULL ;
// }

// template <typename T>
// inline
// iTree<T>* BiTree<T>::root(){
//     return NULL ;
// }

// // template <typename T>
// // Status BiTree<T>::inOrder(
// //     Status (*operate) (iTree<T>*))
// // {
// //     if (not this) return ERROR ;

// //     if (
// //         not 
// //         (
// //             (BiTree<T>*)
// //             this->child(0)
// //         )->inOrder(operate)
// //     )
// //         return ERROR ;
    
// //     if (not operate(this)) 
// //         return ERROR ;
    
// //     if (
// //         not 
// //         (
// //             (BiTree<T>*)
// //             this->child(0)
// //         )->inOrder(operate)
// //     )
// //         return ERROR ;

// //     return OK ;
// // }

// // #include "VisitTree.h"
// template <typename T>
// Status BiTree<T>::inOrder(
//     Status (*operate) (iTree<T>*))
// {
//     //std::cout << "IN ORDER TRAVERSING..." << showTreeNode(this) << std::endl ;
    
    
//     if (this->LChild){
//         if (
//             not
//             this->LChild->inOrder(operate))
//         {
//             return ERROR;
//         }
//     }

//     if (not operate(this)) return ERROR ;

//     if (this->RChild){
//         if (
//             not 
//             this->RChild->inOrder(operate))
//         {
//             return ERROR ;
//         }
//     }
    

//     return OK ;
// }

// // template <typename T>
// // Status BiTree<T>::visitThis(
// //     Status (*operate)(iTree<T>*))
// // {
// //     operate(this);
// //     return OK ;
// // }
// #endif