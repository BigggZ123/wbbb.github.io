#include <iostream>
using namespace std ;
#include <vector>

class Base{
    public :
        virtual void show(){
            cout << "Hello world" << endl ;
        }
};

class Derived : public Base{

};

int main(){
    vector<Derived*> vd ;
    Base* b = new Derived ;
    Derived* d = new Derived;
    vd.push_back(d);
    cout << vd[0] << endl ;

    vd.push_back( dynamic_cast<Derived*>(b));
    cout << vd[1] << endl ;
    vd.push_back((Derived*)(new Base));
    cout << vd[2] << endl;
    return 0 ;
}