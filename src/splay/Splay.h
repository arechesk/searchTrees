//
// Created by Aleksandr Kulikov on 28/12/2018.
//

#ifndef TREES_SPLAY_H
#define TREES_SPLAY_H

#include "SplayNode.h"
namespace splay {
    template<typename Key, typename Value>
    struct Splay {



        void insert(Key k, Value v){
            find(k);
            SplayNode<Key, Value> *new_node = new SplayNode<Key, Value>(k, v);
            if (!root) {
                root = new_node;
                return;
            }
            SplayNode<Key, Value> *temp = root;
            if (k < temp->key) {
                SplayNode<Key, Value> *left = temp->left;
                temp->left = nullptr;
                root = new_node;
                root->set_right(temp);
                root->set_left(left);
            } else {
                SplayNode<Key, Value> *right = temp->right;
                temp->right = nullptr;
                root = new_node;
                root->set_right(right);
                root->set_left(temp);
            }
        }

        void erase(Key k){
            find(k);
            if (!root || root->key != k) {
                return;
            }
            SplayNode<Key, Value> *to_delete = root; // TODO: delete it

            if (!root->right && !root->left) {
                root = nullptr;
                return;
            }

            if (root->right == nullptr || root->left == nullptr) {
                root = root->right ? root->right : root->left;
                root->parent = nullptr;
                return;
            }


            SplayNode<Key, Value> *right_subtree = root->right;
            root = root->left;
            root->parent = nullptr;

            find(k);
            root->set_right(right_subtree);
        }

        Value *find(Key k){
            SplayNode<Key, Value> *temp = root;
            SplayNode<Key, Value> *prev = nullptr;
            while (temp != nullptr) {
                prev = temp;
                if (k < temp->key) {
                    temp = temp->left;
                } else if (k > temp->key) {
                    temp = temp->right;
                } else {
                    splay(temp);
                    return &(root->value);
                }
            }
            if (prev) splay(prev);
            return nullptr;
        }

    private:
        SplayNode<Key, Value> *root = nullptr;

        void rotate(SplayNode<Key, Value> *parent, SplayNode<Key, Value> *child) {
            SplayNode<Key, Value> *grandparent = parent->parent;

            if (parent->left == child) {
                parent->set_left(child->right);
                child->set_right(parent);
            } else {
                parent->set_right(child->left);
                child->set_left(parent);
            }

            if (!grandparent) {
                root = child;
                child->parent = nullptr;
            } else if (grandparent->left == parent) {
                grandparent->set_left(child);
            } else {
                grandparent->set_right(child);
            }
        }

        void splay(SplayNode<Key, Value> *node) {
            while (node != root) {
                SplayNode<Key, Value> *parent = node->parent;
                SplayNode<Key, Value> *grandparent = node->parent->parent;

                if (parent == root) {
                    // zig
                    rotate(parent, node);
                    break;
                }

                if ((grandparent->left && grandparent->left->left == node) ||
                    (grandparent->right && grandparent->right->right == node)) {
                    //zig-zig
                    rotate(grandparent, parent);
                    rotate(parent, node);
                } else {
                    //zig-zag
                    rotate(parent, node);
                    rotate(grandparent, node);
                }
            }
        }

    };

}
#endif //TREES_SPLAY_H
