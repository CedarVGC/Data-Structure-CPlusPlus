//
// Created by Administrator on 2020/7/27.
//

#ifndef DATA_STRUCTURE_C_GREAH_H
#define DATA_STRUCTURE_C_GREAH_H
//边和图的定义
template <typename T>
class Edge{
public:
    int start=0;
    int end=0;
    T weight;
    Edge()= default;
    Edge(int st,int en,T w);
    bool operator >(Edge oneEdge);
    bool operator <(Edge oneEdge);
};

template <typename T>
Edge<T>::Edge(int st, int en, T w) {
    start=st;
    end=en;
    weight=w;
}

template <typename T>
bool  Edge<T>::operator<(Edge oneEdge) {
    return this->weight<oneEdge.weight;
}

template <typename T>
bool  Edge<T>::operator>(Edge oneEdge) {
    return this->weight>oneEdge.weight;
}

template <typename T>
class Graph{
public:
    int vertexNum=0;
    int edgeNum=0;
    int* Mark= nullptr;
    Graph()= default;
    Graph(int verticesNum);
    ~Graph();
    virtual Edge<T> FirstEdge(int oneVertex)=0;
    virtual Edge<T> NextEdge(Edge<T> oneEdge)=0;
    virtual bool isEdge(Edge<T> oneEdge)=0;
    virtual void setEdge(int start,int end,T weight)=0;
    virtual void delEdge(int start,int end)=0;
    virtual void show()=0;
};

template <typename T>
Graph<T>::Graph(int verticesNum) {
    vertexNum=verticesNum;
    Mark=new int[vertexNum];
    for (int i=0;i<vertexNum;i++){
        Mark[i]=0;
    }
}

template <typename T>
Graph<T>::~Graph() {
    delete [] Mark;
}


#endif //DATA_STRUCTURE_C_GREAH_H
