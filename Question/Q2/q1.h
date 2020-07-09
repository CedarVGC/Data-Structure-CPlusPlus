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
}

template <typename T>
void Exchange_Reverse(Sqlist<T> &L,int left,int right){
    for(int start=left,end=right;start<end;start++,end--){
        T temp=L.GetElem(start);
        L.SetElem(start,L.GetElem(end));
        L.SetElem(end,temp);
    }
}

//8题
template <typename T>
void Exchange(Sqlist<T> &L,int m,int n){
    Exchange_Reverse(L,0,m+n-1);
    Exchange_Reverse(L,0,n-1);
    Exchange_Reverse(L,n,m+n-1);
}
//9题
template <typename T>
void SearchExchangeInsert(Sqlist<T> &L,T x){
    if(L.Empty()||L.GetElem(0)>x){
        L.ListInsert(0,x);
    }
    for(int i=0;i<L.Length();i++){
        if(L.GetElem(i)==x){
            if(i+1<L.Length()){
                T temp=L.GetElem(i);
                L.SetElem(i,L.GetElem(i+1));
                L.SetElem(i+1,temp);
            }
            return;
        }
    }
    L.ListInsert(x);
}

//10题
template <typename T>
void Converse(Sqlist<T> & L,int p){
    Exchange_Reverse(L,0,p-1);
    Exchange_Reverse(L,p,L.Length()-1);
    Exchange_Reverse(L,0,L.Length()-1);

}

//11题
template <typename T>
void M_Search(Sqlist<T> &L){

}
//12题
template <typename T>
int Majority(Sqlist<T> &L){

}
//13题
template <typename T>
int FindMissMin(Sqlist<T> &L){
    int *temp;
    temp=new int[L.Length()]();
    for(int i=0;i<L.Length();i++){
        if(L.GetElem(i)>0){
            temp[i]=1;
        }
    }
    for(int i=0;i<L.Length();i++){
        if(temp[i]==0){
            return i+1;
        }
    }
    return L.Length()+1;
}
#endif //DATA_STRUCTURE_C_Q1_H
