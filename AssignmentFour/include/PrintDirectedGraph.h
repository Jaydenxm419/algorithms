#ifndef PRINT_DIRECTED_GRAPH_H
#define PRINT_DIRECTED_GRAPH_H
#include <vector>
using namespace std;

class DirectedGraph;

/* This class prints graphs in different ways  */
class PrintDirectedGraph {
    public:
        PrintDirectedGraph();
        void printAdjancencyList(vector<DirectedGraph*> graphs);
        void printGraphEdges(vector<DirectedGraph*> graphs);
        void printVertexWeights(vector<DirectedGraph*> graphs);
        void printBellmanFord(vector<DirectedGraph*> graphs);
};

extern PrintDirectedGraph print;
#endif