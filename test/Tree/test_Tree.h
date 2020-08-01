//
// Created by Administrator on 2020/7/12.
//
#ifndef DATA_STRUCTURE_C_TEST_TREE_H
#define DATA_STRUCTURE_C_TEST_TREE_H

#include "..\..\include\Tree\Traverse.h"
void test_Tree(){
    int data[]={1,2,3,0,4};
    BinaryTree<int> q(data,5);
    //levelOrder(q.root);
    //PreOrder(q.root);
    //std::cout<<std::endl;
    //InOrder(q.root);
    PostOrder(q.root);
    std::cout<<std::endl;
    PostOrder2(q.root);

}

void test_SearchTree(){
    BinarySearchTree<int> q;
    q.insertNode(4);
    q.insertNode(2);
    q.insertNode(1);
    q.insertNode(3);
    q.insertNode(5);
    //q.deleteByCopy(2);
    q.deleteByMerging(2);
    levelOrder(q.root);

}
#endif //DATA_STRUCTURE_C_TEST_TREE_H
