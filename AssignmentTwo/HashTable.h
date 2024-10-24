#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "node.h"

class HashTable {
private:
    int HASH_TABLE_SIZE;  // Member variable (dynamic, not const)
    Node** buckets;
public:
    HashTable(int TABLE_SIZE);
    int makeHashCode(std::string str); // Declaration
    void analyzeHashCode(int *hashValues);
    void populateHashTable(std::string item);
    int getValueFromHashTable(std::string item);
};
// Initialize an array

// Load items 

// Use hashing function to decide which "bucket" an item goes into

// Once right bucket is found
    // Utilize node class for linking each item to each other at an index

// Retrieve same 42 items a count the comparisons get + comparisons

#endif