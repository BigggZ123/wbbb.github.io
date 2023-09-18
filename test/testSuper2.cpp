#include <iostream>
using namespace std ;

class A{
    public :
        virtual void Hello(){
            cout << "Hello !" << endl ;
        }
};

class B :public A {
    public :
        void Hello () override{
            cout << "B say:"<< endl ;
            A::Hello();
        }
        A* get(){
            return new B;
        }
};

int main(){
    B b ;
    A* pa = b.get();

    pa->Hello() ;

    return 0 ;
}