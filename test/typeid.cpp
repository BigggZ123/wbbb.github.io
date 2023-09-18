#include <iostream>
#include <typeinfo>
using namespace std ;

class A{
    public :
        virtual void f(){
            cout << "Level 1 : this is A" << endl ;
        }
};
class B :public A {
    public :
        void f() override{
            cout << "Level 2 : this is B" << endl ; 
        }
};
class C : public A{
    public :
        void f () override {
            cout << "Level 2 : this is C " << endl ;
        }
};

class D : public B{
    public :
        void f() override{
            cout << "Level 3 : this is D " << endl ;
        }
};


int main(){
    A* pb = new B ;
    A* pc = new C ;
    B* pd = new D ;
    
    pb->f() ;
    A* pa =  (dynamic_cast<A*>(pb));
    return 0 ;
}