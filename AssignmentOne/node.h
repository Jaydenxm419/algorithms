// AssignmentOne/Node.h
#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    // Data members
    std::string data;
    Node* next;

    // Constructor
    Node(const std::string& value);

    // Function to set the next node
    void setNext(Node* nextNode);

    // Function to get the next node
    Node* getNext() const;

    // Function to get the node's data
    std::string getData() const;
};

#endif
