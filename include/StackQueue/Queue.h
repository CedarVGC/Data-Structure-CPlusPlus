//
// Created by Administrator on 2020/7/10.
//
#ifndef DATA_STRUCTURE_C_QUEUE_H
#define DATA_STRUCTURE_C_QUEUE_H
#include <iostream>
template <typename T>
class Queue{
public:
    T* data;
    int front=0;//头指针
    int rear=0;//尾指针
    int MaxSize=50;
    Queue() ;
    ~Queue();
    void Expansion();//队列扩容
    bool QueueEmpty();
    bool QueueFull();
    int GetLength();
    void EnQueue(const T& x);
    bool DeQueue();
    T& GetHead();
    void Print_Queue();
};

template <typename T>
Queue<T>::Queue() {
    data=new T[MaxSize];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
bool Queue<T>::QueueEmpty() {
    return rear==front;
}

template <typename T>
bool Queue<T>::QueueFull() {
    return (rear+1)%MaxSize==front;
}

template <typename T>
int Queue<T>::GetLength() {
    return (rear-front+MaxSize)%MaxSize;
}

template <typename T>
void Queue<T>::Expansion() {
    T* NewData=new T[MaxSize*2];
    for(int start=front,i=0;start!=rear;start=(start+1)%MaxSize,i++){
        NewData[i]=data[front];
    }
    delete[] data;
    data=NewData;
    front=0;
    rear=MaxSize;
    MaxSize*=2;
}

template <typename T>
void Queue<T>::EnQueue(const T &x) {
    if(QueueFull()){
        Expansion();
    } else{
        data[rear]=x;
        rear=(rear+1)%MaxSize;
    }
}

template <typename T>
bool Queue<T>::DeQueue() {
    if(QueueEmpty()){
        return false;
    } else{
        front=(front+1)%MaxSize;
        return true;
    }
}

template <typename T>
T& Queue<T>::GetHead() {
    return data[front];
}

template <typename T>
void Queue<T>::Print_Queue() {
    for(int start=front;start!=rear;start=(start+1)%MaxSize){
        std::cout<<data[start]<<std::endl;
    }
}
#endif //DATA_STRUCTURE_C_QUEUE_H
