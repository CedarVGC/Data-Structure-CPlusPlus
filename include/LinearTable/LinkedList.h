//
// Created by Administrator on 2020/7/7.
//
#ifndef DATA_STRUCTURE_C_LINKEDLIST_H
#define DATA_STRUCTURE_C_LINKEDLIST_H
#include <iostream>
template <typename T>
class LNode{
    T data;
    LNode* next=NULL;
    LNode(){};
    LNode(T d){data=d;}
    LNode(T d,LNode* n){data=d;next=n;};
    ~LNode();
};
#endif //DATA_STRUCTURE_C_LINKEDLIST_H
