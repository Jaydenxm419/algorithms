#include "HashTable.h"
#include <algorithm> 
#include <cctype> 
#include <iostream>
#include <string>

// Set hash table size
HashTable::HashTable() : HASH_TABLE_SIZE(250) {}

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