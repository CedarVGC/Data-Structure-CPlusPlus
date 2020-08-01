//
// Created by Administrator on 2020/7/27.
//

#ifndef DATA_STRUCTURE_C_ADJGRAPH_H
#define DATA_STRUCTURE_C_ADJGRAPH_H
#define MAX_WEIGHT 99999
#include "iostream"
#include "Greah.h"
template <typename T>
class AdjGraph:public Graph<T>{
public:
    T **matrix= nullptr;
    AdjGraph()= default;
    AdjGraph(int verticesNum);
    ~AdjGraph();
    Edge<T> FirstEdge(int oneVertex);
    Edge<T> NextEdge(Edge<T> oneEdge);
    bool isEdge(Edge<T> oneEdge);
    void setEdge(int start,int end,T weight);
    void delEdge(int start,int end);
    void setDoubleEdge(int start,int end,T weight);
    void show();
};

template <typename T>
AdjGraph<T>::AdjGraph(int verticesNum):Graph<T>(verticesNum){
    matrix=new T*[verticesNum];
    for(int i=0;i<verticesNum;i++){
        matrix[i]=new T[verticesNum];
    }

    for (int i=0;i<verticesNum;i++){
        for (int j=0;j<verticesNum;j++){
            matrix[i][j]=i==j?0:MAX_WEIGHT;
        }
    }
}

template <typename T>
AdjGraph<T>::~AdjGraph() {
    for (int i=0;i<Graph<T>::vertexNum;i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

template <typename T>
Edge<T> AdjGraph<T>::FirstEdge(int oneVertex) {
    Edge<T> temp;
    temp.start=oneVertex;
    for (int i=0;i<Graph<T>::vertexNum;i++){
        if(matrix[oneVertex][i]!=0&&matrix[oneVertex][i]!=MAX_WEIGHT){
            temp.end=i;
            temp.weight=matrix[oneVertex][i];
            break;
        }
    }
    return temp;
}

template <typename T>
Edge<T> AdjGraph<T>::NextEdge(Edge<T> oneEdge) {
    Edge<T> temp(0,-1,0);
    temp.start=oneEdge.start;
    for (int i=oneEdge.end+1;i<Graph<T>::vertexNum;i++){
        if(matrix[oneEdge.start][i]!=0&&matrix[oneEdge.start][i]!=MAX_WEIGHT){
            temp.end=i;
            temp.weight=matrix[oneEdge.start][i];
            break;
        }
    }
    return temp;
}

template <typename T>
bool AdjGraph<T>::isEdge(Edge<T> oneEdge) {
    return oneEdge.weight>0&&oneEdge.weight<MAX_WEIGHT&&oneEdge.end>=0;
}

template <typename T>
void AdjGraph<T>::setEdge(int start, int end, T weight) {
    if(matrix[start][end]==MAX_WEIGHT){
        Graph<T>::edgeNum++;
    }
    matrix[start][end]=weight;
}

template <typename T>
void AdjGraph<T>::setDoubleEdge(int start, int end, T weight) {
    if(matrix[start][end]==MAX_WEIGHT){
        Graph<T>::edgeNum++;
    }
    if(matrix[end][start]==MAX_WEIGHT){
        Graph<T>::edgeNum++;
    }
    matrix[start][end]=weight;
    matrix[end][start]=weight;
}

template <typename T>
void AdjGraph<T>::delEdge(int start, int end) {
    if(matrix[start][end]!=MAX_WEIGHT){
        Graph<T>::edgeNum--;
    }
    matrix[start][end]=MAX_WEIGHT;
}

template <typename T>
void AdjGraph<T>::show() {
    std::cout<<"共"<<Graph<T>::vertexNum<<"个顶点"<<std::endl;
    for(int i=0;i<Graph<T>::vertexNum;i++){
        std::cout<<"第"<<i+1<<"个点，与之连接的点是：";
        for(int j=0;j<Graph<T>::vertexNum;j++){
            if(matrix[i][j]!=0&&matrix[i][j]!=MAX_WEIGHT){
                std::cout<<j+1<<" ";
            }
        }
        std::cout<<std::endl;
    }

}
#endif //DATA_STRUCTURE_C_ADJGRAPH_H
