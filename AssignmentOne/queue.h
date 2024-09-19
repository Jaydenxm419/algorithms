// AssignmentOne/queue.h
// This class is the outline of a queue built from the outline of a linked list using the node class
// "First in First Out"
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h" // Include the header file for the Node class
#include <string>

class Queue
{
private:
    Node *head; // The head (front) of the queue (line)
    Node *tail; // The tail (back) of the queue (line)

public:
    Queue(); // Constructor outline
    void enqueue(std::string data); // Enqueue function outline (putting data on the line)
    std::string dequeue(); // Dequeue functon outline (taking data out of the line)
    bool isEmpty(); // Returns if the queue is empty ot not
};

#endif