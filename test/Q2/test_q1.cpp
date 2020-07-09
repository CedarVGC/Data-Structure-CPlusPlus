//
// Created by Administrator on 2020/7/7.
//
#include "test_q1.h"
void test_Q2(){
    int x=0;
    std::cin>>x;
    switch (x){
        case 3:
            test_del_x();
            break;
        case 4:
            test_del_s_t2();
            break;
        case 5:
            test_del_s_t();
            break;
        case 6:
            test_del_Same();
            break;
        case 7:
            test_Merge();
            break;
        case 8:
            test_Exchange();
            break;
        case 9:
            test_SearchExchangeInsert();
            break;
        case 10:
            test_Converse();
            break;
        case 13:
            test_FindMissMin();
            break;
        default:
            break;
    }
}
void test_del_x(){
    int arr[]={2,3,2,2,4};
    Sqlist<int> s(arr,sizeof(arr)/sizeof(int));
    s.PrintList();
    del_x(s,2);
    s.PrintList();
}

void test_del_s_t2(){
    int arr[]={1,2,3,4,5};
    Sqlist<int> s(arr,sizeof(arr)/sizeof(int));
    s.PrintList();
    Del_s_t2(s,3,4);
    s.PrintList();
}

void test_del_s_t(){
    int arr[]={1,3,5,5,3,3,5};
    Sqlist<int> s(arr,sizeof(arr)/sizeof(int));
    s.PrintList();
    Del_s_t(s,2,4);
    s.PrintList();
}
void test_del_Same(){
    int arr[]={1,2,2,3,4,4,5};
    Sqlist<int> s(arr,sizeof(arr)/sizeof(int));
    s.PrintList();
    del_Same(s);
    s.PrintList();
}

void test_Merge(){
    int arr1[]={1,2,3,4,6};
    Sqlist<int> s1(arr1,sizeof(arr1)/sizeof(int));
    int arr2[]={1,2,3,5,7};
    Sqlist<int> s2(arr2,sizeof(arr2)/sizeof(int));
    int arr3[]={0,0,0,0,0,0,0,0,0,0};
    Sqlist<int> s3(arr3,sizeof(arr3)/sizeof(int));
    s3.PrintList();
    Merge(s1,s2,s3);
    s3.PrintList();
}

void test_Exchange(){
    int arr1[]={1,2,3,4,5};
    Sqlist<int> s1(arr1,sizeof(arr1)/sizeof(int));
    s1.PrintList();
    Exchange(s1,3,2);
    s1.PrintList();
}

void test_Converse(){
    int arr1[]={1,2,3,4,5};
    Sqlist<int> s1(arr1,sizeof(arr1)/sizeof(int));
    s1.PrintList();
    Converse(s1,3);
    s1.PrintList();
}

void test_SearchExchangeInsert(){
    int arr1[]={1,2,3,4,5};
    Sqlist<int> s1(arr1,sizeof(arr1)/sizeof(int));
    s1.PrintList();
    SearchExchangeInsert(s1,5);
    s1.PrintList();
}

void test_FindMissMin(){
    int arr1[]={-5,3,2,3};
    Sqlist<int> s1(arr1,sizeof(arr1)/sizeof(int));
    s1.PrintList();
    std::cout<<FindMissMin(s1)<<std::endl;
    int arr2[]={1,2,3};
    Sqlist<int> s2(arr2,sizeof(arr2)/sizeof(int));
    s1.PrintList();
    std::cout<<FindMissMin(s2)<<std::endl;
}
