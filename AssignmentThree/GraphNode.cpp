#include <iostream>
#include <string>
#include "GraphNode.h"

GraphNode::GraphNode(const std::string& id) : identifier(id), neighbors(), processed(false) {}

// Get node
const std::string& GraphNode::getNodeId() {
    return identifier;
}

void GraphNode::addNeighbor(GraphNode* newNeighbor) {
    neighbors.push_back(newNeighbor);
}

const std::vector<GraphNode*>& GraphNode::getNeighbors() const {
    return neighbors;
}

bool GraphNode::getStatus() const {
    return processed;
}

void GraphNode::setStatus(bool status) {
    processed = status;
}