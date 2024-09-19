// AssignmentOne/stack.h
// This class is the outline of a stack built from the outline of a linked list using the node class
// "First in Last Out"
#ifndef STACK_H
#define STACK_H
#include "node.h"  // Include the header file for the Node class
#include <string>

class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack();  // Constructor
    void push(std::string data);  // Method to push an element onto the stack
    std::string pop();  // Method to pop an element from the stack
};

#endif // STACK_H
