#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

class HashTable {
private:
    const int HASH_TABLE_SIZE;
public:
    HashTable(); // Constructor
    int makeHashCode(std::string str); // Declaration
};
// Initialize an array

// Load items 

// Use hashing function to decide which "bucket" an item goes into

// Once right bucket is found
    // Utilize node class for linking each item to each other at an index

// Retrieve same 42 items a count the comparisons get + comparisons

#endif