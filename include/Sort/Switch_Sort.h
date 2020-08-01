//
// Created by Administrator on 2020/7/30.
//
#ifndef DATA_STRUCTURE_C_SWITCH_SORT_H
#define DATA_STRUCTURE_C_SWITCH_SORT_H
//冒泡排序
template <typename T>
void BubbleSort(T data[],int n){
    for (int i=0;i<n;i++){
        for (int j=1;j<n-i;j++){
            if(data[j]<data[j-1]){
                T t=data[j];
                data[j]=data[j-1];
                data[j-1]=t;
            }
        }
    }
}
//快速排序
template <typename T>
int Partition1(T data[],int left,int right){
    T pivot=data[left];
    while (left<right){
        while (left<right&&data[right]>pivot){
            right--;
        }
        data[left]=data[right];
        while (left<right&&data[left]<=pivot){
            left++;
        }
        data[right]=data[left];
    }
    data[left]=pivot;
    return left;
}

template <typename T>
int Partition2(T data[],int left,int right){
    T pivot =data[left];
    int start=left;
    while(left<=right){
        while (left<=right&&data[left]<=pivot){
            left++;
        }
        while (left<=right&&data[right]>pivot){
            right--;
        }
        if(left<right){
            T temp=data[right];
            data[right]=data[left];
            data[left]=temp;
            right--;
            left++;
        }
    }
    T temp=data[start];
    data[start]=data[right];
    data[right]=temp;
    return right;
}
template <typename T>
void QuickSort(T data[],int left,int right){
    if(left<right){
        int p=Partition2(data,left,right);
        QuickSort(data,left,p-1);
        QuickSort(data,p+1,right);
    }
}
#endif //DATA_STRUCTURE_C_SWITCH_SORT_H
