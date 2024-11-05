// AssignmentThree/BinarySearchTree.cpp
#include "BinarySearchTree.h"
#include "BinarySearchTreeNode.h"
#include <iostream>
#include <string>

// Create a tree, initialize the root pointer
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Set the root of the tree
void BinarySearchTree::setRoot(const std::string& rt) {
    if (root == nullptr) {
        root = new BSTNode(rt);
    }
}

// Get the root
BSTNode* BinarySearchTree::getRoot() {
    return root;
}

std::string BinarySearchTree::insertNode(BSTNode *newNode) {
    return helpInsertNode(newNode, this->getRoot());
}

std::string BinarySearchTree::helpInsertNode(BSTNode *newNode, BSTNode *root) {
    return newNode->getData();
}








