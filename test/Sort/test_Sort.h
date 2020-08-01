//
// Created by Administrator on 2020/7/30.
//
#ifndef DATA_STRUCTURE_C_TEST_SORT_H
#define DATA_STRUCTURE_C_TEST_SORT_H
#define  ARR_SIZE(a)  (sizeof((a))/sizeof((a[0])))
#include "../../include/Sort/InsertionSort.h"
#include "../../include/Sort/Switch_Sort.h"
void test_InsertionSort(){
    int s[] ={32,18,65,48,27,9};
    //InsertionSort(s,ARR_SIZE(s));
    //ShellSort(s,ARR_SIZE(s));
    //BubbleSort(s,ARR_SIZE(s));
    QuickSort(s,0,ARR_SIZE(s)-1);
    Show(s,ARR_SIZE(s));
}
#endif //DATA_STRUCTURE_C_TEST_SORT_H
