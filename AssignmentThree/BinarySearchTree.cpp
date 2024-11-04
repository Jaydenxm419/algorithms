#include "node.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>

// Constructor to initialize left, right, and root pointers to null
BinarySearchTree::BinarySearchTree() : right(nullptr), left(nullptr), root(nullptr) {}

// Set the left child of a node
void BinarySearchTree::setLeft(Node *newNode) {
  left = newNode;
}
// Get the left child of a node
Node* BinarySearchTree::getLeft() {
  return left;
}
// Set the right child of a node
void BinarySearchTree::setRight(Node *newNode) {
  right = newNode;
}
// Get the right child of a node
Node* BinarySearchTree::getRight() {
  return right;
}

// Method to insert a node into the tree
std::string BinarySearchTree::insertNode(Node* newNode) {
  return helpInsertNode(newNode, root);
}

std::string BinarySearchTree::helpInsertNode(Node *newNode, Node *root) {
  bool arrivedAtLeaf = false; // Used to signify bottom of tree
  // Loop until the bottom of the tree is found
  while(!arrivedAtLeaf) {
    if (root == nullptr) { // Make the newNode the root 
      root = newNode;
      arrivedAtLeaf = true;
    }
    if (newNode->getData() <= root->getData()) {
        setLeft(helpInsertNode(newNode, root->getLeft())); // Follow the left chain
    }
    if (newNode->getData() >= root->getData()) {
        setRight(helpInsertNode(newNode, root->getRight())); // Follow the right chain
    }
  }
    return root->getData();
}

std::string BinarySearchTree::findNode(Node *node) {
    return helpFindNode(Node *node, Node *root);
}

std::string BinarySearchTree::helpFindNode(Node *node, Node *root) {
    return root.getData();
}

