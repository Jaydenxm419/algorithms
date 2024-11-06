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

// Get the root of the tree
BSTNode* BinarySearchTree::getRoot() {
    return root;
}

// Insert a node in the tree
BSTNode* BinarySearchTree::insertNode(BSTNode *newNode) {
    BSTNode* value;
    // Set the root if its a new tree
    if (this->getRoot() == nullptr) {
        this->setRoot(newNode->getData());
        value = this->getRoot();
    } else {
        value = helpInsertNode(newNode, this->getRoot());
    }
    return value;
}

// Helper method for insertNode
BSTNode* BinarySearchTree::helpInsertNode(BSTNode *newNode, BSTNode *root) {
    // For traversing
    BSTNode* current = root; 
    BSTNode* parent = nullptr;
    // Traverse to the leaf nodes 
    while(current != nullptr) {
        parent = current; // Make the current the new parent
        if (newNode->getData() >= current->getData()) {
            current = current->getRight();
        } else  {
            current = current->getLeft();
        }
    }
    // Insert the new node
    if (newNode->getData() >= parent->getData()) {
        parent->setRight(newNode);
    } else {
        parent->setLeft(newNode);
    }
    return newNode;
}









