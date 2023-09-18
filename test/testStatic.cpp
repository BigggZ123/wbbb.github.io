#include <iostream>
using namespace std ;

class C{
    public :
        int count(){
            static int x ;
            x ++ ;
            return x ;
        }
};

int main(){
    C a , b ;
    cout << a.count() << endl ;
    cout << b.count() << endl ;
}