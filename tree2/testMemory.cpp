#include <iostream>
using namespace std ;

class A{
    public :
        void f(){
            for (int i = 0 ; i < 10 ; i ++){
                for (int j = 0 ; j < 10 ; j ++){
                    cout << (i * j) << endl ;
                }
            }
        }
};

int main(){
    A a ;
    cout << sizeof (A) << endl ;
    cout << sizeof (a) << endl ;
    a.f();
    return 0 ;
}