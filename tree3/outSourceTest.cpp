#include <iostream>
#include "BiTree.h"
#include "TreeOperate.h"
using namespace std ;

int main(){
    BiTree<char>* t = stdBiTreeDemo() ;

    //t[0].visitThis(showTreeNode);
    //cout << t[0].depth() << endl ;
    //t[0].inOrder(showTreeNode);
    t[0].inOrder(new showNodeData<char>);
    
    delete t ;
}