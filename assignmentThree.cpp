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

void runBinarySearchTreeTest() {

    // File of items to be read into array
    ifstream file("magicitems.txt");
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
    std::cout << BST->getNode("Book of Stealth")->getData();
}

int main() {
    
    // Test for binary search tree
    runBinarySearchTreeTest();

    return 0;
}




