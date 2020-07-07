//
// Created by Administrator on 2020/7/7.
//
#ifndef DATA_STRUCTURE_C_Q1_H
#define DATA_STRUCTURE_C_Q1_H
#include "../../include/LinearTable/SequenceTable.h"
template <typename T>
bool Del_Min(Sqlist<T> &L,T &value){
    if(L.Empty()){
        return false;
    }
    T min=L.GetElem(0);
    int id=0;
    for(int i=1;i<L.Length();i++){
        if(min>L.GetElem(i)){
            min=L.GetElem(i);
            id=i;
        }
    }
    L.SetElem(id,L.GetElem(L.Length()-1));
    L.ListDelete();
    return true;
}

template <typename T>
void Reverse(Sqlist<T> &L){
    for(int start=0,end=L.Length()-1;start<end;start++,end--){
       T temp=L.GetElem(start);
       L.SetElem(start,L.GetElem(end));
       L.SetElem(end,temp);
    }
}

template <typename T>
void del_x(Sqlist<T> &L,T x){
    for(int i=0;i<L.Length();i++){
        if(L.GetElem(i)==x){
            L.ListDelete(i--);
        }
    }
}

template <typename T>
bool Del_s_t2(Sqlist<T> &L,T s,T t){
    if(L.Empty()||s>=t){
        return false;
    }
    int start=0,end=L.Length()-1;
    for(;start<L.Length();start++){
        if(L.GetElem(start)>=s){
            break;
        }
    }
    if(start==L.Length()){
        return true;
    }
    for(;end>=start;end--){
        if(L.GetElem(end)<=t){
            break;
        }
    }
    for (int i=start;i<=end;i++){
        L.ListDelete(start);
    }
}

template <typename T>
bool Del_s_t(Sqlist<T> &L,T s,T t){
    if(L.Empty()||s>=t){
        return false;
    }
    int count=0;
    for(int i=0;i<L.Length();i++){
        if(L.GetElem(i)>=s&&L.GetElem(i)<=t){
            count++;
        } else{
            L.SetElem(i-count,L.GetElem(i));
        }
    }
    L.SetLength(L.Length()-count);
}

template <typename T>
void del_Same(Sqlist<T> &L){
    if(L.Empty()){
        return ;
    }
    int count=0;
    int same=L.GetElem(0);
    for(int i=1;i<L.Length();i++){
        if(L.GetElem(i)==same){
            count++;
        } else{
            same=L.GetElem(i);
            L.SetElem(i-count,L.GetElem(i));
        }
    }
    L.SetLength(L.Length()-count);
}

template <typename T>
void Merge(Sqlist<T> &A,Sqlist<T> &B,Sqlist<T> &C){
    for(int sa=0,sb=0,sc=0;;){
        if(sa==A.Length()&&sb<B.Length()){
            for(;sb<B.Length();sb++,sc++){
                C.SetElem(sc,B.GetElem(sb));
            }
            break;
        }else if(sa<A.Length()&&sb==B.Length()){
            for(;sa<A.Length();sa++,sc++){
                C.SetElem(sc,A.GetElem(sa));
            }
            break;
        } else {
            if(A.GetElem(sa)<B.GetElem(sb)){
                C.SetElem(sc++,A.GetElem(sa++));
            } else{
                C.SetElem(sc++,B.GetElem(sb++));
            }
        }
    }
    return;
}
#endif //DATA_STRUCTURE_C_Q1_H
