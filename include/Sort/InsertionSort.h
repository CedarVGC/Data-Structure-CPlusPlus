//
// Created by Administrator on 2020/7/30.
//

#ifndef DATA_STRUCTURE_C_SORT_H
#define DATA_STRUCTURE_C_SORT_H
#include <iostream>
//显示数组
template <typename T>
void Show(T data,int n){
    for(int i=0;i<n;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

//直接插入排序
template <typename T>
void InsertionSort(T data[],int n){
    for(int p=1;p<n;p++){
        T temp=data[p];
        int i=p-1;
        while (i>=0&&data[i]>temp){
            data[i+1]=data[i];
            i--;
        }
        data[i+1]=temp;
    }
}

//折半查找
template <typename T>
void BinaryInsertionSort(T data[],int n){
    for(int p=1;p<n;p++){
        T temp=data[p];
        int left=0,right=p-1;
        while (left<=right){
            int mid=(left+right)/2;
            if(data[mid]>temp){
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        for (int i=p-1;i>=left;i--){
            data[i+1]=data[i];
        }
        data[left]=temp;
    }
}

template <typename T>
void ShellSort(T data[],int n){
    int d=n/2;
    while (d>=1){
        for (int k=0;k<d;k++){
            for (int i=k+d;i<n;i+=d){
                T temp=data[i];
                int j=i-d;
                while (j>=k&&data[j]>temp){
                    data[j+d]=data[j];
                    j-=d;
                }
                data[j+d]=temp;
            }
        }
        d=d/2;
    }
}
#endif //DATA_STRUCTURE_C_SORT_H
