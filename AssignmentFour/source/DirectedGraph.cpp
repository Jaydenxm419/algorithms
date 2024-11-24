#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"

// Start with an empty directed graph
DirectedGraph::DirectedGraph() : vertices() {}

// Return the vertices in the directed graph
vector<DirectedGraphVertex*> DirectedGraph::getVertices() {
    return vertices;
}