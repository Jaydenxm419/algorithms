#include <string>
#include <vector>
using namespace std;

#ifndef BUILD_DIRECTED_GRAPH_H
#define BUILD_DIRECTED_GRAPH_H

class DirectedGraph;
class DirectedGraphVertex;

/* This class is responsible for building a directed 
graph by utilizing graph, vertex, and edge objects */
class BuildDirectedGraph {
    public:
        BuildDirectedGraph();
        // Initialize a new graph
        DirectedGraph* newGraph();
        // Add a vertex to a graph
        DirectedGraphVertex* newVertex(DirectedGraph* graph, string id);
        // Add an edge between two vertices
        void newEdge(DirectedGraphVertex* fromGraph, DirectedGraphVertex* toGraph, int weight);
        // Add the components to a graph from instructions
        vector<DirectedGraph*> buildGraph(vector<string> instructions);
};

extern BuildDirectedGraph build;

#endif