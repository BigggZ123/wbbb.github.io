#include <iostream>
#include <vector>
using namespace std ;

template <typename T>
class iTreeNode{
    public :
        T data ;
        vector<iTreeNode<T>*> children ;
        virtual void push(iTreeNode<T>* child) = 0 ;
};

template <typename T>
class TreeNode: public iTreeNode<T>{
    public :
        void push (iTreeNode<T>* child) override {
            this->children.push_back(child);
            cout << "succed" << endl ;
        };
};

int main(){
    TreeNode<int> t,s ;
    t.push(&s);

    cout << t.children.size() << endl ;
    return 0 ;
}