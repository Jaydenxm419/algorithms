#include <iostream>
#include <string>
#include "GraphNode.h"

GraphNode::GraphNode(const std::string& id) : identifier(id) {}

// Get node id
const std::string& GraphNode::getNodeId() {
    return identifier;
}