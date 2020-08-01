//
// Created by Administrator on 2020/7/25.
//
#ifndef DATA_STRUCTURE_C_HEAP_H
#define DATA_STRUCTURE_C_HEAP_H
#define SWAP(T,m,n) {T s; s=m, m=n, n=s;}
#include <iostream>
template <typename T>
//最大堆和最小堆
class Heap{
public:
    T* heapArray= nullptr;
    int length=0;
    int MaxSize=50;
    bool isMax= true;
    Heap(bool ismax){isMax=ismax;heapArray=new T[MaxSize];}
    Heap(bool ismax,const T* data,int size);
    ~Heap(){delete[] heapArray;}
    void show();
    void SiftDown(int left);
    void BuildHeap();
    void Insert(const T& data);
    T RemoveTop();

};

template <typename T>
Heap<T>::Heap(bool ismax,const T *data, int size) {
    isMax=ismax;
    heapArray=new T[MaxSize];
    for(int i=0;i<size;i++){
        heapArray[length++]=data[i];
    }
    BuildHeap();
}

template <typename T>
void Heap<T>::BuildHeap() {
    for(int i=length/2-1;i>=0;i--){
        SiftDown(i);
    }
}

template <typename T>
void Heap<T>::SiftDown(int left) {
    int i=left;
    int j=i*2+1;//左孩子
    T temp=heapArray[i];//保存父结点的值
    while (j<length){
        if(isMax){
            if((j<length-1)&&(heapArray[j]<heapArray[j+1])){
                j++;
            }
            if(temp<heapArray[j]){
                heapArray[i]=heapArray[j];
                i=j;
                j=2*j+1;
            } else{
                break;
            }
        } else{
            if((j<length-1)&&(heapArray[j]>heapArray[j+1])){
                j++;
            }
            if(temp>heapArray[j]){
                heapArray[i]=heapArray[j];
                i=j;
                j=2*j+1;
            } else{
                break;
            }
        }
    }
    heapArray[i]=temp;
}

template <typename T>
void Heap<T>::Insert(const T &data) {
    heapArray[length++]=data;
    int i=length-1;
    while(i!=0){
        int parent=i/2-1;
        if(isMax){
            if(parent>=1&&heapArray[parent-1]<heapArray[i-1]){
                SWAP(T,heapArray[parent-1],heapArray[i-1]);
                i=parent;
            } else{
                break;
            }
        } else {
            if (parent>=1&&heapArray[parent-1]>heapArray[i-1]) {
                SWAP(T, heapArray[parent-1], heapArray[i-1]);
                i = parent;
            } else {
                break;
            }
        }
    }
}

template <typename T>
T Heap<T>::RemoveTop() {
    T temp=heapArray[0];
    heapArray[0]=heapArray[--length];
    SiftDown(0);
    return temp;
}

template <typename T>
void Heap<T>::show() {
    for(int i=0;i<length;i++){
        std::cout<<heapArray[i]<<" ";
    }
    std::cout<<std::endl;
}
#endif //DATA_STRUCTURE_C_HEAP_H
