#include <string>
using namespace std;

#ifndef BUILD_DIRECTED_GRAPH_H
#define BUILD_DIRECTED_GRAPH_H

class DirectedGraph;
class DirectedGraphVertex;

class BuildDirectedGraph {
    public:
        BuildDirectedGraph();
        DirectedGraph* newGraph();
        DirectedGraphVertex* newVertex(DirectedGraph* graph, string id);
        void newEdge(DirectedGraphVertex* fromGraph, DirectedGraphVertex* toGraph);
        void buildGraph(vector<string> instructions);
};

extern BuildDirectedGraph build;

#endif