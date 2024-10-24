#include "HashTable.h"
#include "sorting.h"
#include "node.h"
#include <algorithm> 
#include <cctype> 
#include <iostream>
#include <string>

// Set hash table size
HashTable::HashTable(int TABLE_SIZE) : HASH_TABLE_SIZE(TABLE_SIZE) {
    buckets = new Node*[HASH_TABLE_SIZE];  // Allocate an array of pointers to Node
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        buckets[i] = nullptr; // Initialize all pointers to nullptr
    }
}

int HashTable::makeHashCode(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper); // Make string uppercase
    int length = str.length();
    int letterTotal = 0; 

    // Iterate over all letters in the string, totalling their ASCII values.
    for (int i = 0; i < length; i++) {
        char thisLetter = str[i];
        int thisValue = (int)thisLetter;
        letterTotal = letterTotal + thisValue;
    }
    int hashCode = (letterTotal * 1) % HASH_TABLE_SIZE;
    return hashCode;
}

// Check the number of occurrences of hash code
void HashTable::analyzeHashCode(int *hashValues) {
    int asteriskCount = 0;  
    int *bucketCount = new int[HASH_TABLE_SIZE];
    int totalCount = 0;
    int arrayIndex = 0;

    // Sort the array with std::sort
    std::sort(hashValues, hashValues + 666);  // Sorts the first 666 elements of hashValues

    // Output the sorted array
    for (int i = 0; i < 250; i++) { 
        asteriskCount = 0;
        while ((arrayIndex < 666) && (hashValues[arrayIndex] == i)) {
            std::cout << "*";
            asteriskCount = asteriskCount + 1;
            arrayIndex = arrayIndex + 1;
        }
        std::cout << "\n";
        bucketCount[i] = asteriskCount;
        std::cout << asteriskCount;
        std::cout << "\n";
        totalCount = totalCount + asteriskCount;
    } 

    std::cout << "Average Load (Count): ";
    float averageLoad = (float) totalCount / HASH_TABLE_SIZE;
    std::cout << averageLoad << "\n";

    std::cout << "Average Load (Calc): ";
    averageLoad = (float) 666 / HASH_TABLE_SIZE;
    std::cout << averageLoad;
}

void HashTable::populateHashTable(std::string item) {
    // Check to see if the index is empty
    int hashCode = makeHashCode(item);
    Node *node = new Node(item);
    if (buckets[hashCode] == nullptr) {
        buckets[hashCode] = node;
    } else {
        Node* current = buckets[hashCode];
        // Iterate through until the end of the list
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        // Add the desired node to the end of the list
        current->setNext(node);
        // std::cout << "\n";
    }
}

int HashTable::getValueFromHashTable(std::string item) {
    int hashCode = makeHashCode(item); // Get the hash code value
    int index = 0; // Initialize the index to 0 for iterating through the table
    int comparisons = 1; // Initialize to 1 to represent the first get in the array
    Node* current = buckets[hashCode];
    while(current->getData() != item && current != nullptr) {
        current = current->getNext();
        comparisons = comparisons + 1;
    }
    if (current == nullptr) {
        comparisons = -1;
    }
    return comparisons;
}



   

