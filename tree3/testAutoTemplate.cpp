#include <iostream>
using namespace std ;

template <typename T>
class Tool ;
template <typename T>
class Data ;

template <typename T>
class Tool{
    public :
        virtual bool operate (Data<T>* data){
            cout << data->data << endl;
            return true ;
        }
};

template <typename T>
class Data{
    public :
        T data ;
        virtual bool operate (Tool<T>* tool){
            tool->operate(this);
            return true ;
        };
};

template <typename T>
class tTool : public Tool<T>{
    public :
        bool operate (Data<T>*data) override{
            cout << data << " (data): " << data->data << endl ;
            return true ;
        }
};

template <typename T>
class dData : public Data<T>{
    public :
        bool operate (Tool<T>* tool) override{
            cout << "Sub class's operating the data" << endl ;
            tool->operate(this);
            return true ;
        }
};

int main(){
    Data<int> d;
    d.data = 1 ;

    dData<int> dd ;
    dd.operate(new tTool<int>);

    return 0 ;
}