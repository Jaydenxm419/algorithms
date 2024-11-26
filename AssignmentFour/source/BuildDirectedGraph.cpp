#include "AssignmentFour/include/BuildDirectedGraph.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/ParseHeistFile.h"
#include "AssignmentFour/include/ProjectConstants.h"
#include "AssignmentFour/include/Search.h"
#include "AssignmentFour/include/DirectedGraphEdge.h"
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

// Create a new edge instance between two vertices
void BuildDirectedGraph::newEdge(DirectedGraphVertex* fromVertex, DirectedGraphVertex* toVertex, int weight) {
    DirectedGraphEdge *edge = new DirectedGraphEdge(toVertex, weight);
    fromVertex->addNeighbor(edge);
}

// Build graphs of vertices and edges
vector<DirectedGraph*> BuildDirectedGraph::buildGraph(vector<string> instructions) {  
    // To build a graph
    DirectedGraph* graph;
    vector<DirectedGraph*> graphs;
    // To build a vertex
    DirectedGraphVertex* vertex;
    vector<string> vertexInfo;
    // To build an edge 
    vector<DirectedGraphVertex*> vertices;
    DirectedGraphVertex* fromVertex;
    DirectedGraphVertex* toVertex;
    vector<string> edgeInfo;
    int weight;
    // Iterate through all instructions
    for (int i = 0; i < instructions.size(); i++) {
        // Make graphs, vertices, and edges based on the text file
        if (instructions[i].find(NEW_GRAPH_SUBSTRING) != string::npos) {
           graph = newGraph();
           graphs.push_back(graph);
        } else if (instructions[i].find(ADD_VERTEX_SUBSTRING) != string::npos) {
           vertexInfo = parse.parseGraphInstruction(instructions[i]);
           vertex = newVertex(graph, vertexInfo[0]);
        } else if (instructions[i].find(ADD_EDGE_SUBSTRING) != string::npos) {
           edgeInfo = parse.parseGraphInstruction(instructions[i]);
           vertices = graph->getVertices();
           // Get the 'from' vertex
           fromVertex = doSearch.doVertexSearch(edgeInfo[0], vertices);
           // Get the 'to' vertex
           toVertex = doSearch.doVertexSearch(edgeInfo[1], vertices);
           // Get the weight of the edge
           weight = std::stoi(edgeInfo[2]);
           newEdge(fromVertex, toVertex, weight);
        }
    }
    return graphs;
}

BuildDirectedGraph build;