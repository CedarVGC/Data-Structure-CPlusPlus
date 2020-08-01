//
// Created by Administrator on 2020/7/20.
//
#ifndef DATA_STRUCTURE_C_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_C_BINARYSEARCHTREE_H
#include "BiTNode.h"
template <typename T>
class BinarySearchTreeNode :public BiTNode<T>{
public:
    BinarySearchTreeNode(){
    }
    BinarySearchTreeNode(const T& key){
        BiTNode<T>::data=key;
    }
    ~BinarySearchTreeNode()= default;
};

//二叉搜索树
template <typename T>
class BinarySearchTree:public BinaryTree<T>{
public:
    BinarySearchTreeNode<T>* root=NULL;
    BinarySearchTree()= default;
    ~BinarySearchTree()= default;
    BiTNode<T>* search(const T& key);
    void insertNode(const T& key);
    void deleteByMerging(const T& key);
    void deleteByCopy(const T& key);
};

template <typename T>
BiTNode<T>* BinarySearchTree<T>::search(const T& key) {
    BiTNode<T>* current=root;
    while((NULL!=current)&&(key!=current->data)){
        current=(key<current->data)?current->lchild:current->rchild;
    }
    return current;
}

template <typename T>
void BinarySearchTree<T>::insertNode(const T& key) {
    if(root==NULL){
        root=new BinarySearchTreeNode<T>(key);
        return;
    }
    BiTNode<T> *p=root,*prev=NULL;
    while(p!=NULL){
        prev=p;
        p=p->data>key?p->lchild:p->rchild;
    }
    if(prev->data<key){
        prev->rchild=new BinarySearchTreeNode<T>(key);
    } else{
        prev->lchild=new BinarySearchTreeNode<T>(key);
    }
}

template <typename T>
void BinarySearchTree<T>::deleteByMerging(const T& key) {
    BiTNode<T>* prev=NULL,*current=root;
    bool turn = true;//该结点为父结点左孩子还是右孩子
    while((NULL!=current)&&(key!=current->data)){
        prev=current;
        if(key<current->data){
            current=current->lchild;
            turn= true;
        } else{
            current=current->rchild;
            turn= false;
        }

    }
    //如果没有右孩子，用其左孩子代替此结点
    if(current->rchild==NULL){
        if(turn){
            prev->lchild=current->lchild;
        } else{
            prev->rchild=current->lchild;
        }
    } else if(current->lchild==NULL){ //如果没有左孩子，用其右孩子代替此结点
        if(turn){
            prev->lchild=current->rchild;
        } else{
            prev->rchild=current->rchild;
        }
    } else{
        BiTNode<T>*node=current->lchild;
        //找到当前结点左子树的最大结点
        while (node->rchild!=NULL){
            node=node->rchild;
        }
        //将查找到的结点的有指针赋值为被删除结点的右子树的根
        node->rchild=current->rchild;
        if(turn){
            prev->lchild=current->lchild;
        } else{
            prev->rchild=current->lchild;
        }
    }
    delete current;
}

template <typename T>
void BinarySearchTree<T>::deleteByCopy(const T& key){
    //查找关键码为key的结点
    BiTNode<T>* prev=NULL,*current=root;
    bool turn = true;//该结点为父结点左孩子还是右孩子
    while((NULL!=current)&&(key!=current->data)){
        prev=current;
        if(key<current->data){
            current=current->lchild;
            turn= true;
        } else{
            current=current->rchild;
            turn= false;
        }

    }
    //如果没有右孩子，用其左孩子代替此结点
    if(current->rchild==NULL){
        if(turn){
            prev->lchild=current->lchild;
        } else{
            prev->rchild=current->lchild;
        }
    } else if(current->lchild==NULL){ //如果没有左孩子，用其右孩子代替此结点
        if(turn){
            prev->lchild=current->rchild;
        } else{
            prev->rchild=current->rchild;
        }
    } else{
        BiTNode<T>* temp=current,*node=current->lchild;
        //找到当前结点左子树的最大结点
        while (node->rchild!=NULL){
            temp=node;
            node=node->rchild;
        }
        current->data=node->data;
        if(temp==current){
            temp->lchild=node->lchild;
        } else{
            temp->rchild=node->lchild;
        }
        delete node;
    }
}
#endif
 //DATA_STRUCTURE_C_BINARYSEARCHTREE_H
