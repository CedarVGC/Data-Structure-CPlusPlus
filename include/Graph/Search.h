//
// Created by Administrator on 2020/7/28.
//

#ifndef DATA_STRUCTURE_C_SEARCH_H
#define DATA_STRUCTURE_C_SEARCH_H
#include "AdjGraph.h"
#include "../StackQueue/Queue.h"
void visit(int v){
    std::cout<<v<<" ";
}

//深度优先遍历
template <typename T>
void DFS(Graph<T>* &g,int v){
    g->Mark[v]=1;
    visit(v);
    for(Edge<T> e=g->FirstEdge(v);g->isEdge(e);e=g->NextEdge(e)){
        if(g->Mark[e.end]==0){
            DFS(g,e.end);
        }
    }
}

template <typename T>
void DFSTraverse(Graph<T>* &g){
    for (int i=0;i<g->vertexNum;i++){
        g->Mark[i]=0;
    }
    for (int i=0;i<g->vertexNum;i++){
        if(g->Mark[i]==0){
            DFS(g,i);
        }
    }
    std::cout<<std::endl;
}
//广度优先搜索
template <typename T>
void BFS(Graph<T>* &g,int v){
    Queue<int> q;
    g->Mark[v]=1;
    visit(v);
    q.EnQueue(v);
    while (!q.QueueEmpty()){
        int u=q.GetHead();
        q.DeQueue();
        for(Edge<T> e=g->FirstEdge(u);g->isEdge(e);e=g->NextEdge(e)){
            if(g->Mark[e.end]==0){
                visit(e.end);
                g->Mark[e.end]=1;
                q.EnQueue(e.end);
            }

        }
    }
}

template <typename T>
void BFSTraverse(Graph<T>* &g){
    for(int i=0;i<g->vertexNum;i++ ){
        g->Mark[i]=0;
    }
    for(int i=0;i<g->vertexNum;i++ ){
        if(g->Mark[i]==0){
            BFS(g,i);
        }
    }
    std::cout<<std::endl;
}

#endif //DATA_STRUCTURE_C_SEARCH_H
