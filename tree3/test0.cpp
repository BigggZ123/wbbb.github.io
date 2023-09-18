#include <iostream>
#include "iBiTree.h"
#include "BiTree.h"
#include "TreeOperate.h"
using namespace std ;

int main(){
    BiTree<int> bt[10] ;
    bt[0].setLChild(&bt[1]);
    for (int i = 0 ; i < 10 ; i ++){
        bt[i].data() = i ;
    }

    for (int i = 0 ; i < 9 ; i ++){
        bt[i].setLChild(&bt[i+1]);
    }
    // cout << bt[9].parent() << endl ;
    // cout << bt[9].root() << endl ;
    //cout << (bt[0].included(new BiTree<int>)) << endl ;
    bt[0].levelOrder(new showNodeData<int>);
    return 0 ;
}