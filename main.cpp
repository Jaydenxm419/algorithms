// main.cpp
#include <iostream>
#include "AssignmentOne/node.h" 
#include <fstream>
#include <string>
#include <vector>

int main() {
        using namespace std;
        // File of items to be read into array
        ifstream file("magicitems.txt");
        // Items in file
        string item;
        // Items array that holds magic items from text file
        vector<string> items;

        // Check if the input file exists
        if (file) {
            // Iterate each line of the text file into the items array
            while (getline(file, item)) {
                items.push_back(item);
            }
            // Close the file to prevent errors
            file.close();
            // Retrieve the size of the array for manipulation
            int n = items.size();
            for (int i = 0; i < n; i++) {
                Node* node = new Node(items[i]);
                Node* nextNode = new Node(items[i + 1]);
                node->setNext(nextNode);
                std::cout << node->getData() << " -> ";
                std::cout << nextNode->getData() << "\n";
            }
        // Handle error if the file doesn't exist
}       else {
            cerr << "ERROR: File may be open or does not exist!" << endl;
            return 1;
        }
        return 0;
}

