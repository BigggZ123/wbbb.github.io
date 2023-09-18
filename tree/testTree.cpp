#include "tree.h"

// Status visit(auto node){
//     cout << node->data << endl ;
//     return OK ;
// }

int main(){
    node<int> t[10];
    for (int i = 1 ; i < 10 ; i ++){
        t[0].push(&t[i]);
    }

    //cout << t[0].degree() << endl ;
    t[0].clear(0);
    cout << t[0].degree() << endl ;
    return 0 ; 
}