//
// Created by Aleksandr Kulikov on 28/12/2018.
//

#ifndef TREES_AVL_H
#define TREES_AVL_H

#include "AVLNode.h"
namespace avl {

    template <typename Key, typename Value>
    AVLNode<Key, Value>* rotate_left(AVLNode<Key, Value>* node) {
        AVLNode<Key, Value>* p = node->right;
        node->right = p->left;
        p->left = node;
        node->update();
        p->update();
        return p;
    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *rotate_right(AVLNode<Key, Value>* node) {
        AVLNode<Key, Value>* p = node->left;
        node->left = p->right;
        p->right = node;
        node->update();
        p->update();
        return p;
    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *balance(AVLNode<Key, Value>* node) {
        node->update();
        int bf = node->balance();
        if (bf == 2) {
            if (node->right->balance() < 0) {
                node->right = rotate_right(node->right);
            }
            return rotate_left(node);
        }
        if (bf == -2) {
            if (node->left->balance() > 0) {
                node->left = rotate_left(node->left);
            }
            return rotate_right(node);
        }
        return node;
    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *insert(AVLNode<Key, Value> *node, Key key, Value value) {
        if (!node) return new AVLNode<Key, Value>(key, value);
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }
        return balance(node);

    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *find_min(AVLNode<Key, Value>* node) {
        return node->left ? find_min(node->left) : node;
    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *remove_min(AVLNode<Key, Value> *node) {
        if (!node->left) {
            return node->right;
        }
        node->left = remove_min(node->left);
        return balance(node);
    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *remove(AVLNode<Key, Value> *node, Key key) {
        if (!node) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            AVLNode<Key, Value>* left = node->left;
            AVLNode<Key, Value>* right = node->right;
            node->left = nullptr;
            node->right = nullptr;
            delete node;
            if (!right) {
                return left;
            }
            AVLNode<Key, Value>* min = find_min(right);
            min->right = remove_min(right);
            min->left = left;
            return balance(min);
        }
        return balance(node);
    }

    template <typename Key, typename Value>
    AVLNode<Key, Value> *find(AVLNode<Key, Value> *node, Key key) {
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
    }






    template<typename Key, typename Value>
    struct AVL {
        void insert(Key k, Value v){ root = avl::insert(root, k, v);}

        void erase(Key k){root = avl::remove(root, k);}

        Value *find(Key k){
            AVLNode<Key, Value>* result = avl::find(root, k);
            return result ? &result->value : nullptr;
        }




    private:
        AVLNode<Key, Value> *root=nullptr;
    };

}




#endif //TREES_AVL_H
