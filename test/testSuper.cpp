#include <iostream>
using namespace std ;

class A{
    public :
        void Hello(){
            cout << "Hello !" << endl ;
        }
};

class B :public A {
    public :
        void say (){
            this->Hello() ;
        }
};

int main(){
    B b ;
    b.say() ;

    return 0 ;
}