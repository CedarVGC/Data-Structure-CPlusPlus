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
    ~DNode(){ };
};

template <typename T>
class LinkList{
public:
    LNode<T> *head;//头结点
    LNode<T> *tail;//尾指针
    int length=0;//链表长度
    LinkList(){
        head=new LNode<T>();
        tail=head;
    }
    ~LinkList(){
        for(LNode<T> *t=head;t!=NULL;){
            LNode<T> *t_next=t->next;
            delete t;
            t=t_next;
        }
    }
    void List_HeadInsert(T x);
    void List_TailInsert(T x);
    void Insert_Node(int i,T x);
    void delete_Node(int i);
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
    LNode<T>* p=head->next;
    if(i<0||i>length-1) {
        return NULL;
    }else{
        for(int j=0;j<length;j++){
            if(j==i){
                break;
            }
            p=p->next;
        }
    }
    return p;
}

template <typename T>
void LinkList<T>::Insert_Node(int i, T x){
    if(i<0||i>length){
        return;
    }
    if(i==length){
        LNode<T>* temp=new LNode<T>(x);
        tail->next=temp;
        tail=temp;
        length++;
        return;
    }
    int count=0;
    for(auto t_prev=head,t=head->next;t!=NULL;t_prev=t,t=t->next){
        if(i==count){
            LNode<T>* temp=new LNode<T>(x);
            t_prev->next=temp;
            temp->next=t;
            length++;
            break;
        }
        count++;
    }
}

template <typename T>
void LinkList<T>::delete_Node(int i) {
    //std::cout<<tail->data<<"dd";
    if(i<0||i>length-1){
        return;
    }
    int count=0;
    LNode<T>* t_prev=head;
    LNode<T>* t=head->next;
    for(;t!=NULL;t_prev=t,t=t->next){
        if(i==count){
            if(t==tail){
                tail=t_prev;
            }
            t_prev->next=t->next;
            delete t;
            break;
        }
        count++;
    }
}

template <typename T>
void LinkList<T>::PrintLinkList(){
    for(LNode<T>* i=head->next;i!=NULL;i=i->next){
        std::cout<<i->data<<" ";
    }
    std::cout<<std::endl;
}
#endif //DATA_STRUCTURE_C_LINKEDLIST_H
