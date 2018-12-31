//
// Created by Aleksandr Kulikov on 28/12/2018.
//

#ifndef TREES_SPLAYNODE_H
#define TREES_SPLAYNODE_H
template<typename Key, typename Value>
struct SplayNode{
    Key key;
    Value value;

    SplayNode<Key, Value>* left = nullptr;
    SplayNode<Key, Value>* right = nullptr;
    SplayNode<Key, Value>* parent = nullptr;

    SplayNode(Key k, Value v) : key(k), value(v) {};

    void set_left(SplayNode* node) {
        left = node;
        if (left) {
            left->parent = this;
        }
    }

    void set_right(SplayNode* node) {
        right = node;
        if (right) {
            right->parent = this;
        }
    }
};


#endif //TREES_SPLAYNODE_H
