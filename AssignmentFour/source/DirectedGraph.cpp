#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"

// Start with an empty directed graph
DirectedGraph::DirectedGraph() : vertices() {}

// Return the vertices
vector<DirectedGraphVertex*> DirectedGraph::getVertices() {
    return vertices;
}
// Add a vertex
void DirectedGraph::addVertex(DirectedGraphVertex* vertex) {
    this->vertices.push_back(vertex);
}