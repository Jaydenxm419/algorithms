// main.cpp
#include "AssignmentOne/node.h"
#include "AssignmentOne/stack.h"
#include "AssignmentOne/queue.h"
#include "AssignmentOne/sorting.h"
#include "AssignmentTwo/Search.h"
#include "AssignmentTwo/HashTable.h"
#include "AssignmentThree/BinarySearchTree.h"
#include "AssignmentThree/Graph.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void runBinarySearchTreeTest() {

    // File of items to be read into array
    ifstream file("magicitems.txt");
    ifstream bstFile("magicitems-find-in-bst.txt");
    // Items in file
    string item;
    // Items array that holds magic items from text file
    string items[666];
    // Check if the input file exists
    if (file)
    {
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(file, item))
        {
            items[i] = item;
            i++;
        }
        // Close the file to prevent errors
        file.close();
    }
    // Make nodes
    BinarySearchTree *BST = new BinarySearchTree();
    for (int i = 0; i < 666; i++) {
         BSTNode *newNode = new BSTNode(items[i]);  
         BST->insertNode(newNode);  
    }
    // Do in order traversal
    std::cout << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "IN ORDER TRAVERSAL" << "\n";
    std::cout << "--------------------" << "\n";
    BST->doinOrderTraversal();
    
    // Read in BST magic items
    item = "";
    string bstItems[42];
    if (bstFile)
    {
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(bstFile, item))
        {
            bstItems[i] = item;
            i++;
        }
        // Close the file to prevent errors
        file.close();
    }
    // Retrieve each item from bstItems
    std::cout << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "RETRIEVING 42 ITEMS" << "\n";
    std::cout << "--------------------" << "\n";
    for (int i = 0; i < 42; i++) {
        BST->getNode(bstItems[i])->getData();
        std::cout << "\n";
    }
}

void runGraphTest() {
    Graph *graph = new Graph();
    graph->addVertex("1");
    graph->addVertex("2");
    const std::vector<GraphNode*> vertices = graph->getVertices();
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "ID Retrieved: " << vertices[i]->getNodeId() << "\n";
    }
    vertices[0]->addNeighbor(vertices[1]);
    const std::vector<GraphNode*> nodeOneNeighbors = vertices[0]->getNeighbors();
    for (int i = 0; i < neighbors.size(); i++) {
        std::cout << "Neighbor ID Retrieved: " << nodeOneNeighbors[i]->getNodeId() << "\n";
    }
}

int main() {
    
    // Test for binary search tree
    // runBinarySearchTreeTest();
    runGraphTest();

    return 0;
}




