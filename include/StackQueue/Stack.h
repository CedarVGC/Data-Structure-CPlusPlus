//
// Created by Administrator on 2020/7/10.
//

#ifndef DATA_STRUCTURE_C_STACK_H
#define DATA_STRUCTURE_C_STACK_H
#include <iostream>
template <typename T>
class Stack{
public:
    T* data;
    int top=-1;
    int Max_Size=50;
    Stack();
    ~Stack();
    void Expansion();//栈满时扩容
    bool StackEmpty();
    void Push(const T& x);
    bool Pop();
    T& GetTop();
    void Print_Stack();
};

template <typename T>
void Stack<T>::Expansion() {
    Max_Size*=2;
    T* Newdata=new T[Max_Size];
    for (int i=0;i<=top;i++){
        Newdata[i]=data[i];
    }
    delete[] data;
    data=Newdata;
}

template <typename T>
Stack<T>::Stack() {
    data=new T[Max_Size];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
bool Stack<T>::StackEmpty() {
        return top==-1;
}

template<typename T>
void Stack<T>::Push(const T& x){
    if(top==Max_Size-1){
        Expansion();
    }
    data[++top]=x;
}

template<typename T>
bool Stack<T>::Pop() {
    if(top==-1){
        return false;
    } else{
        top--;
        return true;
    }
}

template<typename T>
T& Stack<T>::GetTop() {
    return data[top];
}

template<typename T>
void Stack<T>::Print_Stack() {
    for (int i=0;i<=top;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}
#endif //DATA_STRUCTURE_C_STACK_H
