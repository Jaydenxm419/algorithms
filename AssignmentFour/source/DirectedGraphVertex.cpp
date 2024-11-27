#include "AssignmentFour/include/DirectedGraphVertex.h"
#include <vector>
#include <string>
using namespace std;

DirectedGraphVertex::DirectedGraphVertex(const std::string& identifier) : id(identifier), weight(), predecessor(), neighbors() {}

// Return the neighbors of a vertex
vector<DirectedGraphEdge*> DirectedGraphVertex::getNeighbors() {
    return this->neighbors;
}

// Add a neighbor to the vertex
void DirectedGraphVertex::addNeighbor(DirectedGraphEdge* edge) {
    this->neighbors.push_back(edge);
}

// Return the vertex predecessor
DirectedGraphVertex* DirectedGraphVertex::getPredecessor() {
    return this->predecessor;
}

// Update the vertex predecessor
void DirectedGraphVertex::setPredecessor(DirectedGraphVertex* predecessor) {
    this->predecessor = predecessor;
}

// Return the weight of the shortest path to the vertex
int DirectedGraphVertex::getWeight() {
    return this->weight;
}

// Change the weight of the shortest path
void DirectedGraphVertex::setWeight(long weight) {
    this->weight = weight;
}

// Return the id of the vertex
string DirectedGraphVertex::getId() {
    return this->id;
}



