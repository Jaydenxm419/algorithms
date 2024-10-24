// main.cpp
#include "AssignmentOne/node.h"
#include "AssignmentOne/stack.h"
#include "AssignmentOne/queue.h"
#include "AssignmentOne/sorting.h"
#include "AssignmentTwo/Search.h"
#include "AssignmentTwo/HashTable.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


// Seed the random number generator once at the start of the program
void seedRandom() {
    srand((unsigned) time(NULL));
}
// Get the random number 
int getRandomNumber(){
    return rand() % 666;
}

// Method to pick 42 random items from magic items file
Stack pickRandomItems(std::string *items, int size) {
    Stack stack;
    int numberOfItems = 0; // For limiting the number of selected items
    std::string temp = " "; // For swapping
    // std::string* randomItems = new std::string[42]; // Hold random selected items
    
    // Select 42 random items
    while (numberOfItems < 42 && size > 0) {
        int randomNum = getRandomNumber() % size;  // Get random number
        // randomItems[numberOfItems] = items[randomNum]; //
        stack.push(items[randomNum]); 
        // Swap the item chosen with the last element of the array
        items[randomNum] = temp;
        items[randomNum] = items[size - 1];
        items[size - 1] = temp;
        // Decrement the size of the array to exlude duplicate entries into random items array
        size--;
        // Increment the number of items selected by 1
        numberOfItems++;
    }
    return stack;
}


int main() {
    // Random number seeding
    seedRandom(); 

    // File location
    ifstream file("magicitems.txt");

    // Magic Items Array
    int size = 666; 
    string item; 
    string items[size]; 

    // Read the file of magic items
    if (file) {
        int i = 0;
        while (getline(file, item) && i < size) {
            items[i++] = item;
        }
        file.close();

        // Sort the array of items with merge sort
        Sorting sorting;
        std::string* sortedItems = sorting.doMergeSort(items, size);

        // Make a copy of sortedItems to prevent data loss
        std::string sortedItemsCopy[size]; 
        for (int i = 0; i < size; i++){
            sortedItemsCopy[i] = sortedItems[i];
        }

        

        // Do a search for each item in sortedItemsCopy
        Search search;
        // Get 42 random items
        Stack randomItems = pickRandomItems(sortedItems, size);
        search.doLinearSearch(sortedItemsCopy, randomItems, size);
        // Get 42 additional random items
        randomItems = pickRandomItems(sortedItems, size);
        search.doBinarySearch(sortedItemsCopy, randomItems, size);
       

        // // Define HashTable Object
        HashTable HashTable(250);

        // Populate HashTable with 42 random items
        for (int i = 0; i < size; i++) {
            HashTable.populateHashTable(sortedItemsCopy[i]);
        }

        randomItems = pickRandomItems(sortedItemsCopy, size);
        // Get values from HashTable
        std::cout << "HASHTABLE" << "\n" << "\n";
        float totalComparisons = 0;
        float averageComparisons = 0;
        while(!randomItems.isEmpty()) {
            int comparisons = 0; // Reset comparisons for next item
            std::string item = randomItems.pop(); // Get next item
            comparisons = HashTable.getValueFromHashTable(item); // Retrieve item
            std::cout << item << ": " << " Comparisons: " << comparisons << "\n";
            totalComparisons = totalComparisons + comparisons;
        }
        averageComparisons = totalComparisons / 42.0; 
        std::cout << std::fixed << std::setprecision(2);  // Set precision to 2 decimal places
        std::cout << "\n" << "Average Comparisons: " << averageComparisons << "\n";
        std::cout << "--------------------------------------" << "\n";
    } else {
        cerr << "ERROR: File may be open or does not exist!" << endl;
        return 1;
    }
    return 0;
}


