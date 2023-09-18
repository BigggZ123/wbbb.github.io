#ifndef _VISIT_TREE_H
#define _VISIT_TREE_H

#include "iTree.h"

#ifndef _SHOW_TREE_NODE
#define _SHOW_TREE_NODE
template <typename T>
Status showTreeNode(iTree<T>* tat){
    if (not tat) return OK ;
    std::cout << tat->data() << std::endl ;
    return OK ;
};
#endif


#endif