// AssignmentOne/Node.cpp
// This class is the outline for the a node within a linked list
#include "node.h"

// Constructor
Node::Node(const std::string &value) : data(value), next(nullptr) {}

// Function to set the next node
void Node::setNext(Node *nextNode)
{
    next = nextNode;
}

// Function to get the next node
Node *Node::getNext() const
{
    return next;
}

// Function to get data within a node
std::string Node::getData() const
{
    return data;
}
