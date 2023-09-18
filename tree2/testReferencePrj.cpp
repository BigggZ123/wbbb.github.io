#include <iostream>
using namespace std ;

class C {
    protected:
        C* _ptr ;
    public :
        int data ;
        C*& ptr(){
            return _ptr;
        }
};

int main(){
    //cout << "Hello world" << endl ;
    C a,b;
    C *ptr ;
    a.ptr() = &b ;
    b.data = 10 ;
    ptr = a.ptr() ;
    cout << a.ptr()->data << endl ;
    cout << ptr->ptr()->data << endl ;
    return 0 ;
}