#ifndef _TREE_OPERATE_H
#define _TREE_OPERATE_H

template <typename T>
class showNodeData : public iTreeOperate<T>{
    public :
        Status operate (iBiTree<T>* node) override{
            if (not node)
                return ERROR ;
            
            std::cout << node->data() << std::endl;
            return OK ;
        }
};

#endif