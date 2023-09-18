/*
启发自Tree:
    想通过注入的treeNode来区分普通Tree和biTree
    但是如何在使用biTree时，
        能够通过<T>来直接指定内部的数据类型
        而不是<T,node<T>>这样复杂的输入？
*/

template <class microData>
class DataSet{
    microData data ;
};

template <typename T>
class microDataSet{
    T datas;
};

template <typename T>
using speciaTypeDataSet = DataSet<micorDataSet<T>>;