#include <iostream>
using namespace std ;

class Base{
    public :
        class Show{
            public :
                void show(){
                    cout << "Hello world!" << endl ; 
                }
        };
        Show s;
};

class Child : virtual public Base{

};
class Child::Show{
    public :
        void show(){
            cout << "Hello wooooooooooooooooooooooooooorld!" << endl ;
        }
};

int main(){
    Base b ;
    b.s.show() ;
}