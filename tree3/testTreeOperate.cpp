#include <iostream>
using namespace std ;

#include "BiTree.h"
#include "TreeOperate.h"

int main(){
    BiTree<char>* t = stdBiTreeDemo();

    showNodeData<char> show ;
    show(&t[0]);
    show.operate(&t[1]);

    BiTreeNotEqal<char> antiCompare(&t[1]);
    cout << antiCompare(&t[1]) << endl ;

    return 0 ;
}