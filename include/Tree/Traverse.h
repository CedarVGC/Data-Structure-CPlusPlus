//
// Created by Administrator on 2020/7/12.
//二叉树遍历算法
//
#ifndef DATA_STRUCTURE_C_TRAVERSE_H
#define DATA_STRUCTURE_C_TRAVERSE_H
#include "ThreadBinaryTree.h"
#include "BinarySearchTree.h"
template <typename T>
//访问单个结点
void visit(BiTNode<T> *t) {
    std::cout<<t->data<<" ";
}

//层次遍历
template <typename T>
void levelOrder(BiTNode<T> *root) {
    Queue<BiTNode<T> *>q;
    BiTNode<T>* pointer=root;
    if(pointer!=NULL){
        q.EnQueue(pointer);
    }
    while(!q.QueueEmpty()){
        bool t= true;
        for(int start=q.front;start!=q.rear;start=(start+1)%q.MaxSize){
            if(q.data[start]!=NULL){
                t= false;
            }
        }
        if(t){
            std::cout<<std::endl;
            return;
        }
        pointer=q.GetHead();
        q.DeQueue();
        if(pointer==NULL){
            std::cout<<"0 ";
            q.EnQueue(pointer);
            q.EnQueue(pointer);
        } else{
            std::cout<<pointer->data<<" ";
            q.EnQueue(pointer->lchild);
            q.EnQueue(pointer->rchild);
        }
    }
    std::cout<<std::endl;
}

//先序遍历-递归
template <typename T>
void PreOrder(BiTNode<T>* root){
    if(root!=NULL){
        visit(root);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

//先序遍历-非递归
template <typename T>
void PreOrder2(BiTNode<T>* root) {
    Stack<BiTNode<T>* > s;
    BiTNode<T>* pointer=root;
    while(!s.StackEmpty()||pointer!=NULL){//栈为空时遍历结束
        if(pointer!=NULL){
            visit(pointer);
            if(pointer->rchild!=NULL){
                s.Push(pointer->rchild);//将当前结点的右子树的根入栈
            }
            pointer=pointer->lchild;//转向访问其左子树
        } else{//左子树访问完毕，转向访问右子树
            pointer=s.GetTop();
            s.Pop();
        }
    }
}
//中序遍历-递归
template <typename T>
void InOrder(BiTNode<T>* root){
    if(root!=NULL){
        PreOrder(root->lchild);
        visit(root);
        PreOrder(root->rchild);
    }
}

//中序遍历-非递归
template <typename T>
void InOrder2(BiTNode<T>* root){
    Stack<BiTNode<T>* > s;
    BiTNode<T>* pointer=root;
    while(!s.StackEmpty()||pointer!=NULL){
        if(pointer!=NULL){
            s.Push(pointer);
            pointer=pointer->lchild;
        } else{
            pointer=s.GetTop();
            visit(pointer);
            pointer=pointer->rchild;
            s.Pop();
        }
    }
}

//后序遍历-递归
template <typename T>
void PostOrder(BiTNode<T>* root){
    if(root!=NULL){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        visit(root);
    }
}

//后序遍历-非递归
template <typename T>
void PostOrder2(BiTNode<T>* root){
    Stack<BiTNode<T>* > s;
    BiTNode<T>* pointer=root;
    BiTNode<T>* pre=root;//前一个被访问的结点
    while(pointer!=NULL){
        for(;pointer->lchild!=NULL;pointer=pointer->lchild){
            s.Push(pointer);//向左搜索
        }
        while(pointer!=NULL&&(pointer->rchild==NULL||pointer->rchild==pre)){//结点没有右孩子或右孩子刚被访问过
            visit(pointer);
            pre=pointer;
            if(s.StackEmpty()){
                return;
            }
            pointer=s.GetTop();
            s.Pop();
        }
        s.Push(pointer);
        pointer=pointer->rchild;
    }
}

//中序遍历线索二叉树
template <typename T>
void InOrder_ThreadBinaryTree(ThreadBinaryTreeNode<T>* root){
    ThreadBinaryTreeNode<T>* current=root;
    while(current->lTag==0){
        current=current->lchild;
    }
    while(current!=NULL){
        visit(current);
        if(current->rTag==1){
            current=current->rchild;
        } else{
            current=current->rchild;
            while(current!=NULL&&current->lTag==0){
                current=current->lchild;
            }
        }
    }
}
#endif //DATA_STRUCTURE_C_TRAVERSE_H
