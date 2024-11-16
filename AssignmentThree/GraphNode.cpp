#include <iostream>
#include <string>
#include "GraphNode.h"

GraphNode::GraphNode(const std::string& id) : identifier(id), neighbors(), processed(false) {}

// Get node
const std::string& GraphNode::getNodeId() {
    return identifier;
}
// Add a connection to another vertex
void GraphNode::addNeighbor(GraphNode* newNeighbor) {
    neighbors.push_back(newNeighbor);
}
// Retrieve the neighbors of this vertex
const std::vector<GraphNode*>& GraphNode::getNeighbors() const {
    return neighbors;
}
// Check if the node has been processed in a traversal
bool GraphNode::getStatus() const {
    return processed;
}
// Change the status of processed
void GraphNode::setStatus(bool status) {
    processed = status;
}