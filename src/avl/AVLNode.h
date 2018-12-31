//
// Created by Aleksandr Kulikov on 28/12/2018.
//

#ifndef TREES_AVLNODE_H
#define TREES_AVLNODE_H

#include <algorithm>

template<typename Key, typename Value>
struct AVLNode{
    Key key;
    Value value;

    AVLNode<Key, Value>* left;
    AVLNode<Key, Value>* right;

    int height;
    AVLNode(Key k, Value v){
        key = k;
        value = v;
        left = right = nullptr;
        height = 1;
    }

    ~AVLNode() {
        if (left) delete left;
        if (right) delete right;
    }

    void update() {
        height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;

    }
    int balance() {
        return (right ? right -> height : 0) - (left ? left->height : 0);
    }

};

#endif //TREES_AVLNODE_H
