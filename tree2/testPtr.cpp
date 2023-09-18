#include <iostream>
using namespace std ;

class A{
    protected:
        A*  _classPtr ;
    public:
        int* ptr ;
        A* classPtr() {
            return this->_classPtr;
        };
};


int main(){
    cout << "Hello world!" << endl ;
    A a,b ;
    int x = 10 ;
    b.classPtr() = &a ;
    a.ptr = &x ;
    //a.ptr = NULL ;
    cout << *(b.classPtr()->ptr) << endl;


    return 0 ;
}