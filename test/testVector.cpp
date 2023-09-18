#include <iostream>
#include <vector>
using namespace std ;

int main(){
    vector<int> v(10) ;
    for ( int i = 0 ; i < 10 ; i ++){
        v[i] = i ;
    }

    v.erase(v.begin() + 5) ;

    for (int i = 0 ; i < v.size() ; i ++){
        cout << v[i] << endl ;
    }


    return 0 ; 
}