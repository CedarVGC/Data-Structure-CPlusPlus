//
// Created by Administrator on 2020/7/13.
//

#ifndef DATA_STRUCTURE_C_THREADBINARYTREE_H
#define DATA_STRUCTURE_C_THREADBINARYTREE_H
#include "BiTNode.h"
template <typename T>
class ThreadBinaryTreeNode :public BiTNode<T>{
public:
    int lTag=0;
    int rTag=0;
    ThreadBinaryTreeNode()= default;
    ~ThreadBinaryTreeNode()= default;
};

template <typename T>
class ThreadBinaryTree{
public:
    ThreadBinaryTreeNode<T>* root=NULL;
    ThreadBinaryTree()= default;
    ~ThreadBinaryTree()= default;
    void InThread(ThreadBinaryTreeNode<T>* root,ThreadBinaryTreeNode<T> * &pre);//二叉树线索化
};

template <typename T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTreeNode<T> *root, ThreadBinaryTreeNode<T>* &pre) {
    ThreadBinaryTreeNode<T>* current=root;
    if(current!=NULL){
        InThread(current->lchild,pre);//中序线索化左子树
        if(current->lchild==NULL){
            current->lchild=pre;
            current->lTag=1;
        }
        if((pre!=NULL)&&(pre->rchild==NULL)){
            pre->rchild=root;
            pre->rTag=1;
        }
        pre=current;
        InThread(current->rchild,pre);//中序线索化右子树
    }
}

#endif //DATA_STRUCTURE_C_THREADBINARYTREE_H
