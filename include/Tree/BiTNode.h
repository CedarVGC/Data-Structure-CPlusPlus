//
// Created by Administrator on 2020/7/12.
//
#ifndef DATA_STRUCTURE_C_BITNODE_H
#define DATA_STRUCTURE_C_BITNODE_H
#include <iostream>
#include "..\StackQueue\Queue.h"
#include "..\StackQueue\Stack.h"
template <typename T>
class BiTNode{
public:
    T data;
    BiTNode<T>* lchild=NULL;
    BiTNode<T>* rchild=NULL;
    BiTNode(){};
    BiTNode(const T& a){
        data=a;
    }
    ~BiTNode()=default;
};
template <typename T>
class BinaryTree{
public:
    BiTNode<T>* root=NULL;
    BinaryTree()= default;
    BinaryTree(T* data,int size);
    BinaryTree(BiTNode<T>* t){root=t;}
};

template <typename T>
BinaryTree<T>::BinaryTree(T* data,int size) {
    Queue<BiTNode<T> *> q;
    int i=0;
    root=new BiTNode<T>(data[i++]);
    q.EnQueue(root);
    BiTNode<T>* pointer=NULL;
    while(!q.QueueEmpty()&&i<size){
        pointer=q.GetHead();
        q.DeQueue();
        if(pointer!=NULL){
            if(data[i]!=0){
                pointer->lchild=new BiTNode<T>(data[i]);
            }
            i++;
            if(data[i]!=0){
                pointer->rchild=new BiTNode<T>(data[i]);
            }
            i++;
            q.EnQueue(pointer->lchild);
            q.EnQueue(pointer->rchild);
        }
    }
}
#endif //DATA_STRUCTURE_C_BITNODE_H
