#ifndef _LINK_LIST_H
#define _LINK_LIST_H

//#define _ShowNodeWhenInit
#include "../state.h"
#include "../tool.h"
#include <iostream>
using namespace std ;

template <typename T>
class LinkList{
    //pamameter and data
    public:
        class       ListNode ;  
    protected: 
        ListNode    *head ;
        ListNode    *tail ;
        int         _capicity ;
        int         _size ;
    protected:
    //tool funcs
        //Status      generate    (ListNode* parent);//generate ListNode one by one,base func for expand
        Status      connect     (ListNode* pre , ListNode* post);
    public:
    //funcs that user can use
        LinkList                () ;
        LinkList                (int capicity);
        ~LinkList               ();
        int         size        ()          const   {return _size;};
        int         capicity    ()          const   {return _capicity;};
        const T&    at          (int pos)   const;  //read only
        T&          operator[]  (int pos);
        ListNode*   approach    (int pos);
        Status      expand      (int size);
        Status      traverse    (Status (*visit)(ListNode*));
        Status      traverse    (Status (*visit)(void*));//以获得更大的灵活性
        int         index       (T elem );
        int         index       (T elem , int start , int end , bool reversed = false);
        int         index       (LinkList subList);//kmp
        int         count       (T elem);
        Status      insert      (int pos , T elem);
        Status      append      (T elem);
        T           pop         (int pos) ;
        Status      remove      (T elem , int start , int end , bool reversed = false);
        Status      remove      (T elem);
        //Status      destroy     (int start , int end);
        //Status      destroy     ();
        LinkList    sorted      (Status (*compare)(T x , T y));
        Status      sort        (Status (*compare)(T x , T y));
};

template <typename T>
class LinkList<T>::ListNode{
    public:
        T           data ;
        ListNode    *bef , *aft ;
        Status      operator= (ListNode);
        bool        operator==(T elem);
};

template <typename T>
Status LinkList<T>::ListNode::
    operator= (LinkList<T>::ListNode base)
{
    //only data is copyed , but not the connection
    this->data = base.data ;
    this->bef = NULL ;
    this->aft = NULL ;
    return OK ;
}



template <typename T>
LinkList<T>::LinkList()
    :_capicity(1),_size(0)
{
    //至少1个节点
    this->head = this->tail = new ListNode ;
    //cout << this->head << endl ;
}

template <typename T>
LinkList<T>::LinkList(int capicity)
    : _capicity(capicity) , _size(0)
{
    //request memory
    this->head = this->tail = new ListNode;
    this->head->bef = NULL ;
    //cout << this->head << endl ;
    
    for (int i = 0 ; i < capicity - 1 ; i ++){
        ListNode* tmp = this->tail ;
        this->tail = new ListNode ;

        //cout << this->tail << endl ;
        #ifdef _ShowNodeWhenInit
            cout << "Round " << i << ":\t" ;
        #endif
        this->connect(tmp , this->tail);
        this->tail->aft = NULL;
    }
}

template <typename T>
LinkList<T>::~LinkList() // 析构函数
{
    ListNode* current = this->head; // 从头节点开始
    while (current != NULL) // 当节点不为空时
    {
        ListNode* next = current->aft; // 保存下一个节点的指针
        delete current; // 删除当前节点
        current = next; // 移动到下一个节点
    }
    head = tail = NULL; // 将头尾指针置为空
}


template <typename T>
inline Status
LinkList<T>::connect(ListNode* pre , ListNode *post){
    /*
    if (not pre) return ERROR ;
    if (not post) return ERROR;

    pre->aft = post ;
    post->bef = pre;

    #ifdef _ShowNodeWhenInit
        cout << pre << " and " << post << " is connected!" << endl ;
    #endif
    return OK ;

    */
    if ((not pre) and (not post)) return INFEASIBEL;

    if (not pre){
        post->bef = pre ;
    }
    else
    if (not post){
        pre->aft = post ;
    }else{
        pre->aft = post ;
        post->bef = pre ;
   }
   return OK ;
}

/*
//好像开发过度了......
template <typename T>
inline Status
LinkList<T>::generate(LinkList<T>::ListNode* parent){
    if (not parent) return ERROR ;

    ListNode* child = new ListNode;
    this->connect(parent , child);

    //cout << child << endl ;

    return OK ;
}
*/

//设计访问函数时，好像就不能使用template了...
template <typename T>
Status LinkList<T>::traverse(
    Status (*visit) (LinkList<T>::ListNode*))
{
    if (not visit) return ERROR ;

    ListNode* now = this->head;
    for (int i = 0 ; i < this->size() ; i ++){
        if (now == this->tail->aft) 
            return ERROR ;
        if (not visit(now))
            return ERROR ;
        
        //cout << i << endl ;
        now = now->aft ;
    }
    return OK ;
}

template <typename T>
inline typename LinkList<T>::
    ListNode* LinkList<T>::approach(int pos)
{
    if (pos > this->_capicity - 1) return NULL ;
    if (pos < 0) return NULL ;

    ListNode* idx = this->head ;
    for (int i = 0 ; i < pos ; i ++ ){
        idx = idx->aft ;
    }
    return idx ;
}

template <typename T>
inline const T& 
    LinkList<T>::at (int pos) const
{

    if (pos > this->_capicity - 1) throw "Unvisitable" ;
    if (pos < 0) throw "Unvisitable";

    ListNode* idx = this->head ;
    for (int i = 0 ; i < pos ; i ++ ){
        idx = idx->aft ;
    }
    return idx->data ;

}

template <typename T>
inline T& LinkList<T>::
    operator[] (int pos)
{
    //不知为何，该函数直接不接收(pos > capicity)的情况，导致调都没法调
    //cout << pos << endl ;
    if (pos > this->_capicity){
        cout << "OVERFLOW when use operator [] !!!" << endl;
        throw OVERFLOW ;
    }

    this->_size = max(this->_size + 1, pos);

    ListNode* tmp = this->approach(pos) ;
    #ifdef _ShowNodeWhenInit
        cout << this->head << '\t' << this->tail << endl ;
    #endif
    return tmp->data;
}

template <typename T>
Status LinkList<T>::expand(int size){
    if (size < 0) return ERROR ;

    this->_capicity += size ;
    
    ListNode* tmp ;
    for (int i = 0 ; i < size ; i ++){
        tmp = new ListNode ;
        this->connect(this->tail , tmp) ;
        this->tail = tmp ; 
        this->tail->aft = NULL ;
    }
    this->tail->aft = NULL ;
    return OK ;
}

template <typename T>
int LinkList<T>::index(T elem , int start , int end , bool reversed){
    if (start < 0) return OVERFLOW ;
    if (end > this->_capicity) return OVERFLOW ;

    if (reversed){
        for (int i = start ; i < end ; i ++){
            if (this->at(i) == elem){
                return i ; 
            }
        }
    }else{
        for (int i = end - 1; i >= start ; i --){
            if (this->at(i) == elem){
                return i ;
            }
        }
    }
    
    return INFEASIBEL ;
}

template <typename T>
inline 
int LinkList<T>::index(T elem){
    return this->index(elem , 0 , this->_capicity , false);
}

template <typename T>
inline 
T LinkList<T>::pop(int pos){
    if (pos < 0 or pos > this->_size) throw OVERFLOW ;

    if (pos == 0){
        T elem = this->head->data ;
        ListNode* tmp = this->head ;
        this->head = this->head->aft ;
        this->head->bef = NULL ;
        
        delete tmp;
        this->_size -- ;
        this->_capicity -- ;
        return elem ;
    }
    else
    if (pos == this->_size){
        T elem = this->tail->data ;
        ListNode* tmp = this->tail ;
        this->tail = this->tail->bef;
        this->tail->aft = NULL ;

        delete tmp ;
        this->_size -- ;
        this->_capicity -- ;
        return elem ;
    }else{
        ListNode* tmp = this->approach(pos);
        if (not tmp) throw INFEASIBEL ;
                
        this->connect(tmp->bef,tmp->aft);
        T elem = tmp->data ;
        delete tmp ;
        this->_size -- ;
        this->_capicity -- ;
        return elem;    
    }

}


template <typename T>
inline 
int LinkList<T>::count(T elem)
{
    int count = 0 ; 
    for (ListNode* idx = this->head ; idx != this->tail->aft ; idx = idx->aft){
        if (idx->data == elem){
            count ++ ;
        }
    }
    return count ;
}

template <typename T>
Status LinkList<T>::insert(int pos , T elem){
    if (pos < 0 or pos > this->_capicity) return OVERFLOW;
    
    this->_size = max(this->_size,pos);

    if (pos ==0){
        ListNode* tmp = this->head ;
        this->head = new ListNode ;
        this->head->data = elem ;
        this->connect(this->head , tmp);
        this->head->bef = NULL;
    }
    else
    if (pos == this->_capicity){
        ListNode* tmp = this->tail ;
        this->tail = new ListNode ;
        this->tail->data = elem ;
        this->tail->aft = NULL ;
        this->connect(tmp , this->tail);
    }else{
        ListNode* pre = this->approach(pos - 1);
        ListNode* post= this->approach(pos);
        ListNode* now = new ListNode ;
        now->data = elem ;
        this->connect(pre,now);
        this->connect(now,post);
    }

    this->_size++ ;
    this->_capicity++ ;
    return OK ;
}

template <typename T>
inline 
Status LinkList<T>::append(T elem){
    return this->insert(this->_size , elem);
}

template <typename T>
inline 
Status LinkList<T>::remove(T elem , int start , int end , bool reverse){
    int idx = this->index(elem , start , end , reverse);
    if (idx < 0) 
        return ERROR ;
    else{
        this->pop(idx);
        return OK ;
    }
}

template<typename T>
inline
Status LinkList<T>::remove(T elem){
    return this->remove(elem , 0 , this->_capicity , false);
}

/*
*开发失败
template <typename T>
Status LinkList<T>::destroy(int start , int end){
    // 检查参数合法性
    if (start > end) SWAP(T ,start , end);
    start   =   max(start , 0);
    end     =   min(end , this->_capicity);

    ListNode* pre = this->approach(start - 1);
    ListNode* post= this->approach(end + 1);

    ListNode* idx = this->approach(start);
    for (int i = start ; i <= end ; i ++){ // 修改了循环条件
        //cout << idx << endl ;
        cout << i << endl ;
        ListNode* tmp = idx->aft ;
        if (idx) { // 新增了判断条件
            //connect(idx->bef, idx->aft); // 新增了连接操作
            delete idx;
        }
        
        idx = tmp ;
        
        this->_capicity --;
        if (i < this->_size){
            cout << i << ": size is decresing" << endl ;
            this->_size --;
        }
          
    }
    this->_size = max (this->_size , 0) ;
    return this->connect(pre , post);
}


template <typename T>
inline 
Status LinkList<T>::destroy(){
    return this->destroy(-1,this->_capicity);
}
*/

/*
*无法使用，存在访问越界
template <typename T>
Status LinkList<T>::sort(Status (*cmp)(T x , T y)){
    if (not cmp) return ERROR ;
    cout << "Sorting..." << endl ;
    for (int i = 0 ; i < this->_size - 1 ; i ++){
        for (int j  = 0 ; j < this->_size - 1 - i ; j ++){
            T pre = this->operator[](j);
            T post = this->operator[](j + 1);
            cout << pre << '\t' << post << endl ;
            if (cmp (pre , post)){
                this->operator[](j + 1) =   pre ;
                this->operator[](j)     =   post ;
            }
        }  
    }
    return OK ;
}
*/

/*
template <typename T>
inline LinkList<T>
LinkList<T>::sorted(Status (*cmp)(T x , T y)){

}
*/
#endif