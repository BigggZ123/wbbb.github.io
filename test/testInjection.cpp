#include <iostream>
#include <vector>
using namespace std ;


/*
DEFINITION
*/
template <typename T>
class iTreeNode{
    public :
        T    data ;
        vector<iTreeNode*> children;
    public :
        virtual void push (iTreeNode*);
        virtual int degree () const = 0 ;
};

template <typename T>
class TreeNode : public iTreeNode<T>{
    public :
        void push (iTreeNode<T>*) override;
        int degree () const override ;
};


/*
IMPLEMENTATION
*/
template <typename T>
void TreeNode<T>::push(iTreeNode<T>* child){
    this->children.push_back(child);
}

template <typename T>
int TreeNode<T>::degree() const{
    return this->children.size();
}

int main(){
    TreeNode<int> t[10];
    for ( int i = 0 ; i < 10 ; i ++){
        t[i].data = i ;
    }

    for (int i = 1 ; i < 5 ; i ++){
        t[0].push(&t[i]);
    }


    for (int i = 0 ; i < t[0].degree() ; i ++){
        cout << t[0].children[i].data << endl ;
    }
    return 0 ;
}