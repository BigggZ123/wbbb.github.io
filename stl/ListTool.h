#ifndef _LIST_TOOL_H
#define _LIST_TOOL_H
/*
* (utf-8)
* 这里只做了对
    linear List形状的数组
    最基本的数组
* 的支持
*/

#ifndef _COUNT_H
#define _COUNT_H
template <typename T , long long Size>
int count (T (&list)[Size] , T value){
    int _count = 0 ;
    for (T *cur = std::begin(list) ; cur < std::end(list) ; cur++){
        if (* cur == value){
            _count ++ ;
        }
    }
    return _count ;
}

template <typename T , long long Size>
int count (T (&list)[Size] , int start , int end , T value){
    if (start < 0) return -1 ;
    if (end > Size ) return -1 ;
    if (start > end) return -1 ;

    int _count = 0 ;
    for (T *cur = std::begin(list) + start ; cur < std::begin(list) + end ; cur ++){
        if (* cur == value){
            _count ++ ;
        }
    }
    return _count ;
}

template <
    typename T ,
    template <
        typename = T ,
        typename = std::allocator<T>
    >
        class _Container
>
int count (_Container<T>& list , int start , int end , T value){
    if (start < 0) return -1 ;
    if (start > end) return -1 ;

    int _count = 0 ;
    for (
        typename _Container<T>::iterator 
        it = std::next(
            std::begin(list), start
        );
        it != std::next(
            std::begin(list),end
        ); 
        it ++ 
    ){
        if (*it == value){
            _count ++ ;
        }
    }

    return _count;
}

template <
    typename T ,
    template <
        typename = T ,
        typename = std::allocator<T>
    >
        class _Container
>
int count (_Container<T>& list , T value){
    return count(list,0,list.size(),value);
}

#endif

#ifndef _FILL_H
#define _FILL_H
template <typename T , long long Size>
int fill (
    T (&list)[Size] , int start , int end , T value)
{
    if (start < 0) return -1 ;
    if (end > Size ) return -1 ;
    if (start > end) return -1 ;

    for (T *cur = std::begin(list) + start ; cur < std::begin(list) + end ; cur ++){
        * cur = value ;
    }
    return (end - start) ;
}

template <typename T , long long Size>
int fill(T (&list)[Size] , T value){
    for (T *cur = std::begin(list) ; cur < std::end(list) ; cur++){
        *cur = value ;
    }

    return Size ;
}


template <
    typename T ,
    template <
        typename = T ,
        typename = std::allocator<T>
    >
        class _Container
>
int fill (_Container<T>& list , int start , int end , T value){
    if (start < 0) return -1 ;
    if (start > end) return -1 ;

    for (
        typename _Container<T>::iterator 
        it = std::next(
            std::begin(list), start 
        );
        it != std::next(
            std::begin(list), end 
        ); 
        it ++ 
    ){
        *it = value ;
    }

    return (end - start);
}

template <
    typename T ,
    template <
        typename = T ,
        typename = std::allocator<T>
    >
        class _Container
>
int fill (_Container<T>& list , T value){
    return fill(list , 0 , list.size() , value);
}
#endif

#endif