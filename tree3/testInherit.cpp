#include <iostream>
using namespace std ;

class A{
    public :
        int x {0};
};

template <typename T>
class B : public A{
    public :
        T data ;
};

int main(){
    B<char> b ;
    b.x = 1 ;
    b.data = 'A' ;
    cout << b.data << endl ;
    cout << b.x << endl ;
    return 0 ;
}