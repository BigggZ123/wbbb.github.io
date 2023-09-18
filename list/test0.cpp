#include "LinkList.h"

Status visit(LinkList<char>::ListNode* now){
    if (not now){
        cout << "no such node!" << endl ;
    }else{
        cout << now->data ;
    }
    return OK ;
}

Status visitInt(LinkList<int>::ListNode* now){
    cout << now->data << endl ;
    return OK ;
}

Status cmp (char x , char y){
    return (x > y) ;
}

int main(){
    LinkList<char> string(50);
    string[0] = 'H';
    string[1] = 'e';
    string[2] = 'l';
    string[3] = 'l';
    string[4] = 'o';
    string[5] = ' ';
    string[6] = 'w';
    string[7] = 'o';
    string[8] = 'r';
    string[9] = 'l';
    string[10] = 'd';
    string[11] = '\0'  ;

    //  cout << string.size() << '\t' << string.capicity() << endl ;
    //string.destroy(0,string.size());
    //cout << string.size() << "\t" << string.capicity() << endl ;
    string.traverse(visit) ;
    string.sort(cmp);
    string.traverse(visit);
    cout << endl ;
    //s1.traverse(visit);
}
