//
// Created by Aleksandr Kulikov on 28/12/2018.
//

#ifndef TREES_TREAPNODE_H
#define TREES_TREAPNODE_H

#include <cstdint>
#include <cstdlib>

template<typename Key, typename Value>
struct TreapNode{
    TreapNode *left= nullptr, *right=nullptr;
    Value value;
    Key key;
    int weight;

    TreapNode(Key k,Value v): key(k), value(v){
        weight=rand();
    }
    ~TreapNode(){
        if(left) delete left;
        if(right) delete right;
    }
};


#endif //TREES_TREAPNODE_H
