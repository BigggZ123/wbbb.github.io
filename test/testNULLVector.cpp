#include <iostream>
#include <vector>
using namespace std ;

int main(){
    vector<int*> vp ;
    for (int i = 0 ; i < 10 ; i ++){
        vp.push_back(NULL);
    }
    cout << vp.size() << endl ;
}