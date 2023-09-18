#include <iostream>
#include "iTree.h"
#include "Tree.h"
#include "VisitTree.h"
#include <vector>
using namespace std ;

int main(){
    //cout << sizeof( iTree<vector<int> >  ) << endl ;
    // Tree<int> t[10];
    // for (int i =  0 ; i < 9 ; i ++){
    //     t[i].data() = i ;
    //     //cout << t[i].data() << endl ;
    //     t[i].insert(0,&t[i + 1]);
    // }
    // t[9].data()= 9 ;
    // // cout << t[0].depth() << endl ;
    // // cout << t[9].depth() << endl ;
    // //cout << sizeof (t[0]) << endl ;
    // // cout << sizeof (Tree<int>) << endl;
    // //t[0].preOrder(new iVisitTree<int>);
    // // ShowNodeData<int> show ;
    // // t[0].preOrder(show);
    // //t[0].preOrder(showTreeNode);
    // t[0].postOrder(showTreeNode);

    Tree<char> t[12];
    for (int i = 0 ; i < 12 ; i ++){
        t[i].data() = (char)'A' + i ;
    }
    t[0].addChild(0,&t[1]);
    t[0].addChild(1,&t[2]);
    t[0].addChild(2,&t[3]);
    t[1].addChild(0,&t[4]);
    t[1].addChild(1,&t[5]);
    t[3].addChild(0,&t[6]);
    t[3].addChild(1,&t[7]);
    t[4].addChild(0,&t[8]);
    t[6].addChild(0,&t[9]);
    t[6].addChild(1,&t[10]);
    t[6].addChild(2,&t[11]);
    cout << t[11].depth() << endl ;
    cout << t[0].depth() << endl ;
    cout << t[0].included((Tree<char>*)(new Tree<int>));

    return 0 ;
}