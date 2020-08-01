//
// Created by Administrator on 2020/7/30.
//

#ifndef DATA_STRUCTURE_C_SEARCH_H
#define DATA_STRUCTURE_C_SEARCH_H
//顺序查找
template <typename T>
int Search(T Array[],T key,int n){
    for(int i=0;i<n;i++){
        if(Array[i]==key){
            return i;
        }
    }
    return -1;
}

//折半查找
template <typename T>
int BiSearch(T Array[],T key,int n){
    int left=0;
    int right=n-1;
    while (left<=right){
        int mid=(left+right)/2;
        if (key<Array[mid]){
            right=mid-1;
        } else if(key>Array[mid]){
            left=mid+1;
        } else{
            return mid;
        }
    }
    return -1;
}
#endif //DATA_STRUCTURE_C_SEARCH_H
