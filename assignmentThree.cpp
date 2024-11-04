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
    BST->setRoot("test");
    std::cout << BST->getRoot()->getData();
    return 0;
}


