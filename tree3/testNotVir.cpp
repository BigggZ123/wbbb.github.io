#include <iostream>
using namespace std ;

class A{
    public :
        void f(){
            cout << "A" << endl ;
        }
};

class a : public A{
    public :
        void f(){
            cout << "a" << endl ;
        }
};

int main(){
    a ia ;
    A* pa = &ia ;
    pa->f() ;
    
    return 0 ;
}