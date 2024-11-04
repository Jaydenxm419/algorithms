// AssignmentOne/Node.h
// This class is the outline for the a node within a linked list
#ifndef BinarySearchTreeNode_H
#define BinarySearchTreeNode_H

#include <string>
class BSTNode {
  
public:
  std::string data; // Data within a node
  BSTNode *left; // Left child pointer
  BSTNode *right; // Right child pointer

  // Constructor
  BSTNode(const std::string &value);
  // Set the right child pointer
  void setRight(BSTNode *value);
  // Set the left child pointer
  void setLeft(BSTNode *value);
  // Get the right child
  BSTNode* getRight();
  // Get the left child
  BSTNode* getLeft();
  // Get the data from a node in the tree
  std::string getData();
};

#endif
