//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "../../General/AbstractGraph.h"
#include "../../List/Graph/Edge.h"

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source, int endWord);
        Path* dijkstra(int source , int startWord, int endWord);
        int** floydWarshall();
        void prim();
    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode);
        void breadthFirstSearch(bool* visited, int startNode, int endNode) override;
        void printPath(Path *shortestPaths, int source, int endNode) override;
        Edge* edgeList(int& edgeCount) override;
    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
