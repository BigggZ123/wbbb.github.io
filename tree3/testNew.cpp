#include <iostream>
using namespace std ;

class A{
    public :
        int data ;
        A(int data) : data(data) {};
};

void showData(A* container){
    cout << container->data << endl ;
}

int main(){
    showData(new A(10)) ;

    return 0 ;
}