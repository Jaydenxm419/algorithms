#include "AssignmentFour/include/BuildDirectedGraph.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/ParseHeistFile.h"
#include "AssignmentFour/include/ProjectConstants.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


BuildDirectedGraph::BuildDirectedGraph() {}

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
        } else if (instructions[i].find(ADD_VERTEX_SUBSTRING) != string::npos) {
           vector<string> vertexInfo = parse.parseGraphInstruction(instructions[i]);
           vertex = newVertex(graph, vertexInfo[0]);
        }

    }
}

BuildDirectedGraph build;