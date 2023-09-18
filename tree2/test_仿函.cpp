#include <iostream>
using namespace std ;

class MAX{
    public :
        int operator() (int x , int y ){
            return(
                (x > y) ? 
                x :
                y
            );
        }
};
MAX Max ;

class MIN{
    public :
        template <typename T>
        T operator()  (T x , T y){
            return (
                (x < y) ?
                x :
                y
            );
        }
};
MIN Min;

template <typename T>
class Data{
    public :
        T data ;
};

class iDataCompare{
    public :
        template <typename T>
        T operator() (Data<T> d1 , Data<T> d2);
};

class DataCompare{
    public :
        template <typename T>
        T operator() (Data<T> d1 , Data<T> d2){
            return (
                Min(
                    d1.data,
                    d2.data
                )
            );
        }  
};

DataCompare dc ;

int main(){
    cout << Min('a','b') << endl ;
    Data<char> d1 , d2;
    d1.data = 'a' ; d2.data = 'b'; 
//    cout << Min(d1,d2) << endl ;  
    cout << dc(d1,d2) << endl ;
    return 0 ;
}