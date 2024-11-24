#include "AssignmentFour/include/DirectedGraphEdge.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
using namespace std;

DirectedGraphEdge::DirectedGraphEdge(DirectedGraphVertex *vertex, const int &edgeWeight) : vertex(vertex), edgeWeight(edgeWeight){}

// Return the next vertex pointer
DirectedGraphVertex* DirectedGraphEdge::getVertex() {
    return this->vertex;
}
// Return the weight of the edge
int DirectedGraphEdge::getWeight() {
    return this->edgeWeight;
}