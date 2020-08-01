//
// Created by Administrator on 2020/7/25.
//
#ifndef DATA_STRUCTURE_C_TEST_HEAP_H
#define DATA_STRUCTURE_C_TEST_HEAP_H
#include "..\..\include\Tree\Heap.h"
void test_heap(){
    Heap<int> q(false);
    q.Insert(1);
    q.Insert(2);
    q.Insert(3);
    q.Insert(4);
    q.Insert(5);
    q.RemoveTop();
    q.show();
    int s[]={1,2,3,4,5};
    int size=5;
    Heap<int> p(true,s,size);
    p.RemoveTop();
    p.show();
}
#endif //DATA_STRUCTURE_C_TEST_HEAP_H
