// AssignmentOne/stack.h
// This class is the outline of a stack built from the outline of a linked list using the node class
// "First in Last Out"

#include "stack.h"
#include <stdexcept>

// Constructor definition
Stack::Stack() : top(nullptr) {}

// Method to push an element onto the stack
void Stack::push(std::string data) {
    Node* node = new Node(data);  // Creating a node and adding data to it 
    node->setNext(top);           // Set the new nodes pointer to the current top node
    top = node;                   // Change the top pointer to point to the new node
}

// Method to pop an element from the stack
std::string Stack::pop() {
    // Check to see if the stack is empty
    if (top == nullptr) {
        throw std::out_of_range("Stack is empty");
    }

    std::string data = top->getData(); // Get the data from the top of the stack
    Node* poppedNode = top;        // Hold the previous top's data
    top = top->getNext();          // Update the top pointer to the next node
    delete poppedNode;             // Delete the old top node to prevent data leakage
    return data;   // Return the data as a string
}

bool Stack::isEmpty() {
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}
