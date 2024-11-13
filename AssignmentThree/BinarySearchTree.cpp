// AssignmentThree/BinarySearchTree.cpp
#include "BinarySearchTree.h"
#include "BinarySearchTreeNode.h"
#include <iostream>
#include <string>
using namespace std;

// Create a tree, initialize the root pointer
BinarySearchTree::BinarySearchTree() : root(nullptr), totalComparisons() {}

const int BinarySearchTree::getTotalComparisons() const {
    return this->totalComparisons;
}
// Set the root of the tree
void BinarySearchTree::setRoot(const std::string& rt) {
    if (root == nullptr) {
        root = new BSTNode(rt);
    }
}

// Get the root of the tree
BSTNode* BinarySearchTree::getRoot() const {
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
    vector<std::string> path;
    // Traverse to the leaf nodes 
    while(current != nullptr) {
        parent = current; // Make the current the new parent
        if (newNode->getData() >= current->getData()) {
            current = current->getRight();
            path.push_back("R");
        } else  {
            current = current->getLeft();
            path.push_back("L");
        }
    }
    // Print the path
    std::cout << "Path for: " << newNode->getData() << ": ";
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << "\n";
    // Insert the new node
    if (newNode->getData() >= parent->getData()) {
        parent->setRight(newNode);
    } else {
        parent->setLeft(newNode);
    }
    return newNode;
}

void BinarySearchTree::doinOrderTraversal() const {
    helpInOrderTraversal(this->getRoot());
}

void BinarySearchTree::helpInOrderTraversal(BSTNode* node) const {
    if (node == nullptr) {
        return; 
    }
    helpInOrderTraversal(node->getLeft());
    std::cout << node->getData() << "\n";
    helpInOrderTraversal(node->getRight());
}

BSTNode* BinarySearchTree::getNode(const std::string& value) {
    BSTNode* current = this->getRoot();
    BSTNode* result = nullptr;  
    vector<std::string> path;
    while (current != nullptr) {
        if (current->getData() == value) {
            result = current;
            break;
        } else if (value < current->getData()) {
            current = current->getLeft();
            path.push_back("L");
        } else {
            current = current->getRight();
            path.push_back("R");
        }
    }
    std::cout << value << ": " << "\n";
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << "\n" << "Comparisons: " << path.size() << "\n";
    this->totalComparisons = this->totalComparisons + path.size();
    return result;  
}
