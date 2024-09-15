// main.cpp
#include <iostream>
#include "AssignmentOne/node.h"
#include <fstream>
#include <string>
#include <vector>

int main()
{
    using namespace std;
    // File of items to be read into array
    ifstream file("magicitems.txt");
    // Items in file
    string item;
    // Items array that holds magic items from text file
    int arrSize = 666;
    string items[arrSize];

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
        // Iterrate through the array and add the elements to the linked list
        for (int i = 0; i < arrSize; i++)
        {
            // Declare the previous node
            Node *node = new Node(items[i]);
            // Ensure array overflow is resolved
            if (i < arrSize - 1)
            {
                Node *nextNode = new Node(items[i + 1]);
                node->setNext(nextNode);
            }
            // Set a null pointer at the end of the linked list
            else
            {
                node->setNext(nullptr);
            }
            // Print the previous element and next element
            if (node->getNext() != nullptr)
            { 
                std::cout << node->getData() << " -> ";
                std::cout << node->getNext()->getData() << "\n"; // Print next node's data
            }
            else
            {
                std::cout << node->getData() << " -> ";
                std::cout << "nullptr\n"; // No next node, print nullptr
            }
        }
        // Handle error if the file doesn't exist
    }
    else
    {
        cerr << "ERROR: File may be open or does not exist!" << endl;
        return 1;
    }
    return 0;
}
