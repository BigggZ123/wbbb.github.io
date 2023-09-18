#include <iostream>
using namespace std ;

class A {
    public :
        int count(){
            static int _count ;
            return _count++ ;
        }
};

int main(){
    A a  , b , c;
    cout << a.count() << endl ;
    cout << b.count() << endl ;
    cout << c.count() << endl ;
    return 0 ;
}