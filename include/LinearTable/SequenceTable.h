//
// Created by Administrator on 2020/7/6.
//顺序表数据结构
//
#ifndef DATA_STRUCTURE_C_SEQUENCETABLE_H
#define DATA_STRUCTURE_C_SEQUENCETABLE_H
#include <iostream>
#include <cassert>
template <typename T>
/*顺序表，基于数组实现，存储空间满时自动扩容*/
class Sqlist{
    private:
        T* data;//元素
        int MaxSize=100;//最大容量
        int length=0;//类型定义
    public:
        Sqlist(){data=new T[MaxSize];}
        Sqlist(int MaxSize){this->MaxSize=MaxSize;data=new T[MaxSize];}
        Sqlist(T* data,int size);//数组形式初始化化
        ~Sqlist() {delete [] data;}
        int Length(){ return length;};//表长
        void SetLength(int n){length=n; }
        bool Empty(){ return length==0;}//判空
        T& GetElem(int i);//查找第i位的元素的值
        void SetElem(int i, const T& e);
        int LocateElem(const T &e);//查找第一个值为e的元素的位置
        void ListInsert(const T &e);//在表尾端添加数据
        void ListInsert(int i,const T &e);//在第i号位置插入元素
        void ListDelete();//删除表尾数据
        void ListDelete(int i);//删除表尾第i号位置的数据
        void PrintList();//输出
};

template <typename T>
Sqlist<T>::Sqlist(T* d,int size){
    data=new T[MaxSize];
    for(int i=0;i<size;i++){
        this->ListInsert(d[i]);
    }
}

template <typename T>
T& Sqlist<T>::GetElem(int i) {
    assert(i>=0&&i<length);
    return data[i];
}

template <typename T>
void Sqlist<T>::SetElem(int i, const T &e) {
    assert(i>=0&&i<length);
    data[i]=e;
}

template <typename T>
int Sqlist<T>::LocateElem(const T &e) {
    int i=0;
    for(;i<length;i++){
        if(data[i]==e){
            return i;
        }
    }
    return -1;
}
template <typename T>
void Sqlist<T>::ListInsert(const T &e) {
    if(MaxSize<=length){
        MaxSize*=2;
        T* newdata=new T[MaxSize];
        for(int i=0;i<length;i++){
            newdata[i]=data[i];
        }
        delete[] data;
        data=newdata;
    }
    data[length++]=e;
}

template <typename T>
void Sqlist<T>::ListInsert(int i,const T &e) {
    if(i<0||i>length){
        std::cout<<"i超出范围"<<std::endl;
        return;
    }
    if(MaxSize>length){
        MaxSize*=2;
        T* newdata=new T[MaxSize];
        for(int j=0;j<length;j++)
        {
            newdata[j]=data[j];
        }
        delete [] data;
        data=newdata;
    }
    for(int j=length;j>=i;j--){
        data[j]=data[j-1];
    }
    data[i]=e;
    length++;
}

template <typename T>
void Sqlist<T>::ListDelete() {
    if(length<0){
        std::cout<<"表为空"<<std::endl;
        return;
    }
    length--;
}

template <typename T>
void Sqlist<T>::ListDelete(int i){
    if(i<0||i>length-1){
        std::cout<<"i超出范围"<<std::endl;
        return;
    }
    for(int j=i+1;j<length;j++){
        data[j-1]=data[j];
    }
    length--;
}

template <typename T>
void Sqlist<T>::PrintList() {
    for(int i=0;i<length;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}
#endif //DATA_STRUCTURE_C_SEQUENCETABLE_H
