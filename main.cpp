#include <iostream>
#include<map>
#include<vector>
#include <fstream>
#include "./src/avl/AVL.h"
#include "./src/splay/Splay.h"
#include "./src/treap/treap.h"

using namespace std;
using namespace treap;
using namespace splay;
using namespace avl;



double avl_insert(int i){
    AVL<int,int> avl;
    for(int j=0;j<i;j++){
        avl.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        avl.insert(rand(),rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}
double avl_find(int i){
    AVL<int,int> avl;
    for(int j=0;j<i;j++){
        avl.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        avl.find(rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double avl_remove(int i){
    AVL<int,int> avl;
    for(int j=0;j<i;j++){
        avl.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        avl.erase(rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}

double map_insert(int i){
    std::map<int,int> map;
    for(int j=0;j<i;j++){
        map[rand()]=rand();
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        map[rand()]=rand();
    }

    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double map_find(int i){
    std::map<int,int> map;
    for(int j=0;j<i;j++){
        map[rand()]=rand();
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        map[rand()];
    }

    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double map_remove(int i){
    std::map<int,int> map;
    for(int j=0;j<i;j++){
        map[rand()]=rand();
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        map.erase(rand());
    }

    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}

double splay_insert(int i){
    Splay<int,int> spley;
    for(int j=0;j<i;j++){
        spley.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        spley.insert(rand(),rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double splay_find(int i){
    Splay<int,int> spley;
    for(int j=0;j<i;j++){
        spley.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        spley.find(rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double splay_remove(int i){
    Splay<int,int> spley;
    for(int j=0;j<i;j++){
        spley.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        spley.erase(rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

double treap_insert(int i){
    Treap<int,int> treap;
    for(int j=0;j<i;j++){
        treap.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        treap.insert(rand(),rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double treap_find(int i){
    Treap<int,int> treap;
    for(int j=0;j<i;j++){
        treap.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        treap.find(rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}
double treap_remove(int i){
    Treap<int,int> treap;
    for(int j=0;j<i;j++){
        treap.insert(rand(),rand());
    }
    clock_t start = clock();
    for(int j=0;j<1000;j++){
        treap.erase(rand());
    }
    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

}


int main() {
    std::ofstream out("output.csv");
    out<<"Algorithm, count, time"<<endl;
   // long lowbound=50000000, upbound=lowbound+10000, step=1000;
    int size[10]={0,10,100,1000,10000,100000,1000000,5000000,7000000,9999999};
    for(long i=0;i<10;i+=1){
    out <<"Treap insert, "<<size[i]<<","<< treap_insert(size[i]) << endl;
    out <<"Treap find, "<<size[i]<<","<< treap_find(size[i]) << endl;
    out <<"Treap remove, "<<size[i]<<","<< treap_remove(size[i]) << endl;
    }

    for(long i=0;i<10;i+=1){
        out <<"Splay insert, "<<size[i]<<","<< splay_insert(size[i]) << endl;
        out <<"Splay find, "<<size[i]<<","<< splay_find(size[i]) << endl;
        out <<"Splay remove, "<<size[i]<<","<< splay_remove(size[i]) << endl;
    }

    for(long i=0;i<10;i+=1){
        out <<"Map insert, "<<size[i]<<","<< map_insert(size[i]) << endl;
        out <<"Map find, "<<size[i]<<","<< map_find(size[i]) << endl;
        out <<"Map remove, "<<size[i]<<","<< map_remove(size[i]) << endl;
    }

    for(long i=0;i<10;i+=1){
        out <<"AVL insert, "<<size[i]<<","<< avl_insert(size[i]) << endl;
        out <<"AVL find, "<<size[i]<<","<< avl_find(size[i]) << endl;
        out <<"AVL remove, "<<size[i]<<","<< avl_remove(size[i]) << endl;
    }
    out.close();
    return 0;
}