#include "AssignmentFour/include/BuildDirectedGraph.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


BuildDirectedGraph::BuildDirectedGraph() {}

const string NEW_GRAPH_SUBSTRING = "new graph";
const string NEW_VERTEX_SUBSTRING = "new vertex";
const string NEW_EDGE_SUBSTRING = "new edge";

// Create a new graph instance
DirectedGraph* BuildDirectedGraph::newGraph() {
    DirectedGraph *graph = new DirectedGraph();
    return graph;
}

// Create a new vertex instance in a graph
DirectedGraphVertex* BuildDirectedGraph::newVertex(DirectedGraph* graph, string id) {
    DirectedGraphVertex *vertex = new DirectedGraphVertex(id);
    graph->addVertex(vertex);
    return vertex;
}

void BuildDirectedGraph::newEdge(DirectedGraphVertex* fromVertex, DirectedGraphVertex* toVertex) {

}

void BuildDirectedGraph::buildGraph(vector<string> instructions) {
    // Current graph
    DirectedGraph* graph;
    DirectedGraphVertex* vertex;
    DirectedGraphEdge* edge;
    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i].find(NEW_GRAPH_SUBSTRING) != string::npos) {
           graph = newGraph();
        } else if (instructions[i].find(NEW_VERTEX_SUBSTRING)) {
           vertex = newVertex(graph, "1");
           for (int j = 0; j < graph->getVertices().size(); j++) {
            cout << graph->getVertices()[j]->getId();
           }
           
        }

    }
}

BuildDirectedGraph build;