#include "tree.h"
using namespace std ;


int main(){
    int x = 1 , y = 2 ;
    cout << Equal(x,y) << endl ;

    tree<int> t[10] ;
    cout << Equal(&t[0],&t[1]) << endl ;
    return 0 ;
}