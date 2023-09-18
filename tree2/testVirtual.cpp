#include <iostream>
#include <string>
using namespace std ;



class Virtual {
    protected:
        virtual string Pro() = 0 ;
    public :    
        virtual string Pub() = 0 ;
};

class Concrete : public Virtual{
    protected:
        string Pub() override{
            return "Public in Base Class , Protected in Derived Class" ;
        }
    public:
        string Pro() override{
            return "Protected in Base Class , Public in Derived Class" ;
        }
};

int main(){
    Concrete c ;
    Virtual* v = &c ;
    cout << c.Pro() << endl ;
    cout << v->Pub() << endl ;

    return 0 ;
}