#include <string>
#include <vector>
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
        void newEdge(DirectedGraphVertex* fromGraph, DirectedGraphVertex* toGraph, int weight);
        vector<DirectedGraph*> buildGraph(vector<string> instructions);
};

extern BuildDirectedGraph build;

#endif