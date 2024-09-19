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

    // Function outline to set the next node
    void setNext(Node *nextNode);

    // Function outline to get the next node
    Node *getNext() const;

    // Function outline to get the node's data
    std::string getData() const;
};

#endif
