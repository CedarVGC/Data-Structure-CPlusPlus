//
// Created by Administrator on 2020/7/12.
//

#ifndef DATA_STRUCTURE_C_BITNODE_H
#define DATA_STRUCTURE_C_BITNODE_H
#include <iostream>
template <typename T>
class BiTNode{
public:
    T data;
    BiTNode<T>* lchild=NULL;
    BiTNode<T>* rchild=NULL;
    BiTNode()=default;
    ~BiTNode()=default;
};

template <typename T>
class BinaryTree{
public:
    BiTNode<T>* root=NULL;
    BinaryTree()= default;
    BinaryTree(BiTNode<T>* t){root=t;};
};
#endif //DATA_STRUCTURE_C_BITNODE_H
