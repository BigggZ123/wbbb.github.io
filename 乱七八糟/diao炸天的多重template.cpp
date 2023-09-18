#include <iostream>
#include <vector>
#include <list>
using namespace std ;

template <
    typename T = int , 
    template < typename = T, typename = allocator<T>> class Container = vector
    >
class DataSet{
    public :
        Container<T> data ;
};


int main(){
    DataSet<int,list> d ;
    d.data.push_back(1);
    cout << d.data.front() << endl ;
    return 0 ;
}