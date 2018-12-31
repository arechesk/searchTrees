cmake_minimum_required(VERSION 3.4)
project(trees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/treap/treap.h src/treap/TreapNode.h src/splay/Splay.h src/splay/SplayNode.h src/avl/AVL.h src/avl/AVLNode.h)
add_executable(trees ${SOURCE_FILES})