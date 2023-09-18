#include <iostream>
using namespace std ;

//写一个桶排序
template <typename T>
void bucketSort(T *data , int len){
    
    //1. 先计算出最大值和最小值
    T max = data[0] ;
    T min = data[0] ;
    for(int i = 1 ; i < len ; i++){
        
        if(data[i] > max){
            max = data[i] ;
            
        }
        if(data[i] < min){
            min = data[i] ;
        }
    }
    
    //2. 计算出桶的数量
    int bucketNum = (max - min) / len + 1 ;
    
    //3. 初始化桶
    T **bucket = new T*[bucketNum] ;
    
    for(int i = 0 ; i < bucketNum ; i++){
        bucket[i] = new T[len] ;
        for(int j = 0 ; j < len ; j++){
            
            bucket[i][j] = 0 ;
        }
    }
    
    //4. 开始装桶
    for(int i = 0 ; i < len ; i++){
        
        int index = (data[i] - min) / len ;
        bucket[index][bucket[index][0]] = data[i] ;
        bucket[index][0]++ ;
    }
    
    //5. 开始排序
    int index = 0 ;
    for(int i = 0 ; i < bucketNum ; i++){
        
        int len = bucket[i][0] ;
        for(int j = 0 ; j < len ; j++){
            
            data[index++] = bucket[i][j] ;
        }
    }
    
    //6. 释放内存
    for(int i = 0 ; i < bucketNum ; i++){
        
        delete [] bucket[i] ;
    }
    delete [] bucket ;
}

int main(){
    //写一个带有输出的测试用例
    int data[] = {1,2,3,4,5,6,7,8,9,10} ;
    bucketSort(data,10) ;
    
    for(int i = 0 ; i < 10 ; i++){
        
        cout << data[i] << " " ;
    }
    cout << endl ;
    
    return 0 ;
}
