//
// Created by Aleksandr Kulikov on 28/12/2018.
//

#include <cstdlib>
#include "TreapNode.h"

#ifndef TREES_TREAP_H
#define TREES_TREAP_H
namespace treap {
    template<typename Key, typename Value>
    void merge(TreapNode<Key, Value> *&root, TreapNode<Key, Value> *left, TreapNode<Key, Value> *right) {
        if (!left || !right) {
            root = left ? left : right;
        } else if (left->weight > right->weight) {
            merge(left->right, left->right, right);
            root = left;
        } else {
            merge(right->left, left, right->left);
            root = right;
        }
    };

    template<typename Key, typename Value>
    void split(TreapNode<Key, Value> *root, TreapNode<Key, Value> *&left, TreapNode<Key, Value> *&right, Key key) {
        if (!root) {
            left = right = nullptr;
        } else if (key < root->key) {
            split(root->left, left, root->left, key);
            right = root;
        } else {
            split(root->right, root->right, right, key);
            left = root;
        }
    };

    template<typename Key, typename Value>
    void insert(TreapNode<Key, Value> *&root, TreapNode<Key, Value> *vertex) {
        if (root == nullptr) {
            root = vertex;
        } else if (vertex->weight < root->weight) {
            if (vertex->key < root->key) {
                insert(root->left, vertex);
            } else {
                insert(root->right, vertex);
            }
        } else {
            split(root, vertex->left, vertex->right, vertex->key);
            root = vertex;
        }
    };

    template<typename Key, typename Value>
    void erase(TreapNode<Key, Value> *&root, Key key) {
        if (root == nullptr) {
            return;
        } else if (root->key == key) {
            merge(root, root->left, root->right);
        } else {
            erase(key < root->key ? root->left : root->right, key);
        }
    };

    template<typename Key, typename Value>
    TreapNode<Key, Value> *find(TreapNode<Key, Value> *node, Key key) {
        if (!node) {
            return nullptr;
        }
        if (key < node->key) {
            return find(node->left, key);
        }
        if (key > node->key) {
            return find(node->right, key);
        }
        return node;
    };


    template<typename Key, typename Value>
    struct Treap {
        void insert(Key k, Value v) { treap::insert(root, new TreapNode<Key, Value>(k, v)); }

        void erase(Key k) { treap::erase(root, k); }

        Value *find(Key k) {
            TreapNode<Key, Value> *result = treap::find(root, k);
            return result ? &result->value : nullptr;
        }

    private:
        TreapNode<Key, Value> *root = nullptr;

    };

}

#endif //TREES_TREAP_H


