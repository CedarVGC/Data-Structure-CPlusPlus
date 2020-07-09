//
// Created by Administrator on 2020/7/7.
//
#ifndef DATA_STRUCTURE_C_LINKEDLIST_H
#define DATA_STRUCTURE_C_LINKEDLIST_H
#include <iostream>
template <typename T>
class LNode{
public:
    T data;
    LNode* next=NULL;
    LNode(){};
    LNode(T d){data=d;}
    LNode(T d,LNode* n){data=d;next=n;};
    ~LNode(){};
};

template <typename T>
class DNode{
public:
    T data;
    DNode* prev=NULL;
    DNode* next=NULL;
    DNode(){};
    DNode(T x){data=x;}
    ~DNode(){};
};

template <typename T>
class LinkList{
public:
    LNode<T> *head;//头结点
    LNode<T> *tail;//尾指针
    int length=0;
    LinkList(){
        head=new LNode<T>();
        tail=head;
    }
    ~LinkList(){};
    void List_HeadInsert(T x);
    void List_TailInsert(T x);
    LNode<T>* GetElem(int i);
    void PrintLinkList();
};
template <typename T>
void LinkList<T>::List_HeadInsert(T x){
    LNode<T>* temp=new LNode<T>(x);
    if(tail==head){
        tail=temp;
    }
    temp->next=head->next;
    head->next=temp;
    length++;
}
template <typename T>
void LinkList<T>::List_TailInsert(T x) {
    LNode<T>* temp=new LNode<T>(x);
    tail->next=temp;
    tail=temp;
    length++;
}

template <typename T>
LNode<T>* LinkList<T>::GetElem(int i) {
    LNode<T>* p=head;
    if(i<0||i>length-1) {
        return NULL;
    }else{
        for(int j=0;j<length;j++){
            if(j==i){
                break;
            }
            j++;
            p=p->next;
        }
    }
    return p;
}

template <typename T>
void LinkList<T>::PrintLinkList(){
    for(LNode<T>* i=head->next;i!=NULL;i=i->next){
        std::cout<<i->data<<" ";
    }
    std::cout<<std::endl;
}
#endif //DATA_STRUCTURE_C_LINKEDLIST_H
