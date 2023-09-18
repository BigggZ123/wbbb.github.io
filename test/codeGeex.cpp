#include <iostream>
using namespace std ;

//写一个冒泡排序
template <typename T>
void bubbleSort(T arr[], int len){
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len - 1 - i ; j++){
            if(arr[j] > arr[j+1]){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
            }
        }
    }
}

int main(){
    //写一个带有输出的测试样例
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    bubbleSort(arr, 10);
    for(int i = 0 ; i < 10 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
