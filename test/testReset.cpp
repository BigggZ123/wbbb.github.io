#include <iostream>
using namespace std ;

class Base{
    public :
        int x ;
        Base(){
            this->x = 0 ;
        }
        Base(int num):x(num){};
};

class Child : public Base{
    public:
        Child(){
            this->x = 21 ;
        };
};

int main(){
    Base b ;
    Child c ;
    cout << b.x << endl ;
    cout << c.x << endl ;
    return 0;
}