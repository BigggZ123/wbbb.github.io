#include <iostream>
using namespace std ;

struct Max{
    template <typename T>
    T operator() (T x , T y){
        return ((x>y)?x:y);
    }
};


template <typename T , typename F>
T compare(T a , T b , F func){
    return func(a,b);
}

int main(){
    int x = 1 , y = -2 ;
    Max max ;
    int z = compare(x,y,max);
    cout << z << endl ;
    return 0 ;
}