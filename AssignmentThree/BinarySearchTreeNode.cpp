// AssignmentOne/Node.cpp
/* This class is the outline for a node within a linked list */
#include "BinarySearchTreeNode.h"

// Create a new node for binary tree
BSTNode::BSTNode(const std::string &value) : data(value), left(nullptr), right(nullptr) {}

// Set the right child pointer
void BSTNode::setRight(BSTNode *value) {
    right = value;
}

// Set the left child pointer
void BSTNode::setLeft(BSTNode *value) {
    left = value;
}

// Get the right child
BSTNode* BSTNode::getRight() {
    return right;
}

// Get the left child
BSTNode* BSTNode::getLeft() {
    return left;
}

// Get the data for a node in the binary search tree
std::string BSTNode::getData() {
    return data;
}

