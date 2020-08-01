//
// Created by Administrator on 2020/7/26.
//
#ifndef DATA_STRUCTURE_C_HAFFMANTREE_H
#define DATA_STRUCTURE_C_HAFFMANTREE_H
#include "BiTNode.h"
template <typename T>
class HaffmanTreeNode :public BiTNode<T>{
    HaffmanTreeNode(const T& Data):BiTNode(Data){}
};

template <typename T>
class HaffmanTree{
public:
    HaffmanTreeNode<T>* root=NULL;
    HaffmanTree(T weight[],int n);
};

template <typename T>
HaffmanTree<T>::HaffmanTree(T *weight, int n) {

}

#endif //DATA_STRUCTURE_C_HAFFMANTREE_H
