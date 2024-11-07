// main.cpp
#include "AssignmentOne/node.h"
#include "AssignmentOne/stack.h"
#include "AssignmentOne/queue.h"
#include "AssignmentOne/sorting.h"
#include "AssignmentTwo/Search.h"
#include "AssignmentTwo/HashTable.h"
#include "AssignmentThree/BinarySearchTree.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    BinarySearchTree *BST = new BinarySearchTree();
    BSTNode *newNode = new BSTNode("5");  // Root node
    BSTNode *newNode1 = new BSTNode("7");
    BSTNode *newNode2 = new BSTNode("3");
    BSTNode *newNode3 = new BSTNode("1");

    // Insert nodes into the tree
    BST->insertNode(newNode);  // Sets the root
    BST->insertNode(newNode1);
    BST->insertNode(newNode2);
    BST->insertNode(newNode3);

    std::cout << BST->getNode("7")->getData();

    return 0;
}


