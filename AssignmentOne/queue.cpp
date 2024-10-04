// AssignmentOne/queue.cpp
// This class is the outline of a queue built from the outline of a linked list using the node class
// "First in First Out"
#include "queue.h"
#include <iostream>
#include <stdexcept>

// Constructor that intializes the head and tail of the queue to nullptr
Queue::Queue() : head(nullptr), tail(nullptr) {}

// Method to add data from the tail (back) into the queue
void Queue::enqueue(std::string data)
{
    Node *node = new Node(data); // Create a new node
    if (tail != nullptr) {
        tail->next = node; // Make the tail point at the next node
    }
    tail = node; // Make the new node the current tail
    if (head == nullptr) {
        head = node; // Make the node the head if there isn't currently a head (empty queue)
    }
}

// Method to remove data from the head (front) of the queue 
std::string Queue::dequeue() {
    if (head == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    std::string data = head->getData(); // Get the data of the head to be removed
    Node *oldHead = head; // Placeholder for removing the old head
    head = head->getNext(); // Make the next node in the queue (in the line) the new head
    if (head == nullptr) {
        tail = nullptr;
    }
    delete oldHead; // delete the old head
    return data;
}

bool Queue::isEmpty() {
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
