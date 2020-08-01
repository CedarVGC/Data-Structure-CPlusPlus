//
// Created by Administrator on 2020/7/27.
//

#ifndef DATA_STRUCTURE_C_TEST_GRAPH_H
#define DATA_STRUCTURE_C_TEST_GRAPH_H
#include "../../include/Graph/Search.h"
void test_Graph(){
    AdjGraph<int> a(8);
    a.setDoubleEdge(0,1,1);
    a.setDoubleEdge(0,2,1);
    a.setDoubleEdge(1,3,1);
    a.setDoubleEdge(1,4,1);
    a.setDoubleEdge(2,5,1);
    a.setDoubleEdge(2,6,1);
    a.setDoubleEdge(3,7,1);
    a.setDoubleEdge(4,7,1);
    a.setDoubleEdge(5,6,1);
    Graph<int>* p=&a;
    p->show();
    DFSTraverse(p);
    BFSTraverse(p);
}

#endif //DATA_STRUCTURE_C_TEST_GRAPH_H
