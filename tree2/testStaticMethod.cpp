#include <iostream>
using namespace std ;

class A {
    public :
        static void f(){
            cout << "A::f()"<< endl ;
         }
};

class B : public A{
    public:
        static void f(){
            cout << "B::f()" << endl ;
        }
};

class baseTree{
    public :
        static baseTree* root(){
            return NULL;
        }
};

class dirvedTree{
    protected:
        baseTree* tmp ;
    public :
        dirvedTree(){
            tmp = new baseTree;
        }
        static baseTree* root();
};


int main(){
    return 0 ;
}