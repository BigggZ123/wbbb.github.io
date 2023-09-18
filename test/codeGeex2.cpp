//写一个堆排序
#include <iostream>
#include <algorithm>

void heapAdjust(int a[],int s,int m);

void heapSort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapAdjust(a,i,n);
    }
    for(int i=n-1;i>0;i--)
    {
        std::swap(a[0],a[i]);
        heapAdjust(a,0,i);
    }
}
void heapAdjust(int a[],int i,int n){
    int temp=a[i];
    for(int j=2*i+1;j<n;j=2*j+1)
    {
        if(j<n-1&&a[j]<a[j+1])
        {
            j++;
        }
        if(temp>=a[j])
        {
            break;
        }
        a[i]=a[j];
        i=j;
    }
    a[i]=temp;
}

int main(){
    //写一个带有输出的测试样例

    int a[10]={1,3,5,7,9,2,4,6,8,10};
    heapSort(a,10);
    for(int i=0;i<10;i++)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}