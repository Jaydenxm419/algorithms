// AssignmentOne/Node.h
// This class is the outline for the a node within a linked list
#ifndef NODE_H
#define NODE_H

#include <string>
class Node
{
public:
    // Variables
    std::string data;
    Node *next;

    // Constructor
    Node(const std::string &value);

    // Method outline to set the next node
    void setNext(Node *nextNode);

    // Method outline to get the next node
    Node *getNext() const;

    // Method outline to get the node's data
    std::string getData() const;
};

#endif
