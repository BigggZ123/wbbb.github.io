#include <iostream>
#include "BiTree.h"
#include "VisitTree.h"
using namespace std ;

int main(){
    BiTree<char> t[7];
    for (int i =  0 ; i < 7 ; i ++){
        t[i].data() = 'A' + i ;
        //cout << t[i].data() ;
    }
    t[0].setLChild(&t[1]);
    t[0].setRChild(&t[2]);
    t[1].setLChild(&t[3]);
    t[1].setRChild(&t[4]);
    t[4].setLChild(&t[5]);
    t[4].setRChild(&t[6]);
    //t[0].visitThis(showTreeNode);
    //cout << t[0].depth() << endl ;
    //t[0].inOrder(showTreeNode);
    t[0].preOrder(showTreeNode);
}