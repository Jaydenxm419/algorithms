// main.cpp
#include <iostream>
#include "AssignmentOne/node.h"
#include "AssignmentOne/stack.h"
#include "AssignmentOne/queue.h"
#include "AssignmentOne/sorting.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Method to process items in the array and add them to the linked list
void linkedListTest(std::string items[])
{
    for (int i = 0; i < 666; i++)
    {
        // Declare the current node
        Node *node = new Node(items[i]);

        // Prevent array overflow
        if (i < 665)
        {
            Node *nextNode = new Node(items[i + 1]);
            node->setNext(nextNode);
        }
        else
        {
            node->setNext(nullptr);
        }

        // Print the current element and next element
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
}

// Method to split strings
vector<char> split(string str, char del)
{
    vector<char> characters; // Characters in the string
    string temp = "";        // Temporary string to filter out "delimeters" (new word for me)

    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] == ' ')
        {
            continue; // Skip spaces
        }
        // If the character is not the "delimeter", add it to the temp string
        if (str[i] != del)
        {
            temp += str[i];
        }
        else
        {
            // Add the characters to the characters vector
            for (int j = 0; j < (int)temp.size(); j++){
                characters.push_back(temp[j]);
            }
            temp = ""; // Reset the temporary string
        }
    }

    // Loop just in case the string doesn't end in the delimeter
    for (int j = 0; j < (int)temp.size(); j++){
        characters.push_back(temp[j]); // Add each character of the last word
    }

    return characters;
}

// Method to search for palindromes in an array
int searchForPalindromes(std::string *items, int size) {
    // Vector to store discovered palindromes
    std::vector<std::string> palindromes;
    // Loop through each word in the array
    for (int i = 0; i < size; i++) {
        Stack stack; // Define the stack for reverse string reading
        Queue queue; // Define the queue for forward string reading
        bool isPalindrome = true;
        char del = ' ';                                 // Split on each character
        vector<char> characters = split(items[i], del); // Call the split function

        // Loop through the characters vector for adding characters
        for (int j = 0; j < (int)characters.size(); j++) {
            stack.push(std::string(1, characters[j]));    // Push onto the stack
            queue.enqueue(std::string(1, characters[j])); // Enqueue onto the queue
        }
        // Loop through the characters vector for comparing characters
        for (int k = 0; k < (int)characters.size(); k++) {
            // Take out the next character from the queue
            std::string queueValue = queue.dequeue();
            // Take out the next character from the stack
            std::string stackValue = stack.pop();
            queueValue[0] = std::tolower(queueValue[0]);
            stackValue[0] = std::tolower(stackValue[0]);
            if (queueValue != stackValue) {
                isPalindrome = false;
                // std::cout << "Mismatch found. Exiting comparison." << std::endl; // Debug output
                break;
            }
        }
        // If the word was a palindrome, add it to the vector
        if (isPalindrome){
            palindromes.push_back(items[i]);
        }
        cout << endl; // New line after each item
    }

    // Print palindromes
    std::cout << "----------------------------------" << "\n";
    std::cout << "Palindromes found: " << std::endl;
    std::cout << "----------------------------------" << "\n";
    for (int i = 0; i < (int)palindromes.size(); i++)
    {
        std::cout << palindromes[i] << std::endl;
    }
    std::cout << "----------------------------------" << "\n";
    std::cout << "There are " << (int)palindromes.size();
    std::cout << " palindromes." << "\n";
    std::cout << "----------------------------------" << "\n";
    std::cout << "\n";
    return 0;
}

// Method that makes all characters in each element lowercase
void toLowercase(std::string *items, int size) {
    for (int i = 0; i < size; ++i) {
        std::transform(items[i].begin(), items[i].end(), items[i].begin(), ::tolower);
    }
}

// Method to do different sorts
void performSort(Sorting& sorting, std::string* items, int size, const std::string& sortType) {
    std::string* shuffledItems = sorting.doKnuthShuffle(items, size); // Store the returned pointer
    toLowercase(shuffledItems, size);  // Apply the lowercase transformation

    if (sortType == "Selection") {
        sorting.doSelectionSort(shuffledItems, size);
    } else if (sortType == "Insertion") {
        sorting.doInsertionSort(shuffledItems, size);
    } else if (sortType == "Merge") {
        sorting.doMergeSort(shuffledItems, size);
    } else if (sortType == "Quick") {
        sorting.doQuickSort(shuffledItems, 0, size);
    }

    std::cout << "----------------------------------" << "\n";
    std::cout << sortType << " Sort\n";
    std::cout << "Number of Comparisons: ";
    std::cout << sorting.comparisonCounter << std::endl;
    // No need to delete shuffledItems, it's not dynamically allocated
    sorting.comparisonCounter = 0;
}

int main() {
    // Random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
    // File of items to be read into array
    ifstream file("magicitems.txt");
    // Items in file
    string item;
    // Items array that holds magic items from text file
    string items[666];

    // Check if the input file exists
    if (file)
    {
        Stack stack;
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(file, item))
        {
            items[i] = item;
            i++;
        }
        // Close the file to prevent errors
        file.close();

        Sorting sorting;
    
        int index = 666;
        // Call sorts
        searchForPalindromes(items, index);
        performSort(sorting, items, index, "Selection");
        performSort(sorting, items, index, "Insertion");
        performSort(sorting, items, index, "Merge");
        performSort(sorting, items, index, "Quick");
        std::cout << "----------------------------------" << "\n";


    return 0;
    }
    else
    {
        cerr << "ERROR: File may be open or does not exist!" << endl;
        return 1;
    }

    return 0;
}
