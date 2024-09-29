#include "sorting.h"
#include <string>


// Selection sorting algorithm
int Sorting::doSelectionSort(std::string* items, int size) {
    std::string min = ""; // Stores the current minimum for the comparision
    std::string temp = ""; // Used for swapping the current and minimum index
    int comparisonCount = 0; // Counter to verify average sort comparisons
    // Iterate through magic items
    for (int i = 0; i < size; ++i) {
        int minIndex = i; // Initialize the minimum index to the current index
        min = items[i]; // Initialize the minimum string value to the current string
        // Iterate through magic items for every item following the current index of i
        for (int j = i; j < size; j++) {
            comparisonCount++; 
            // Compare each string to the current minimum
            if (items[j] < min) {
                min = items[j]; // Define the new minimum
                minIndex = j; // Define location of the new minimum
            }
        }
        // Swap the current string with the minimum string after all strings were compared
        temp = items[i];
        items[i] = items[minIndex];
        items[minIndex] = temp;
    }
    for (int k = 0; k < size; ++k) {
        std::cout << items[k] << "\n"; // Print the items
    }
    std::cout << "Comparision Count: " << comparisonCount;
    std::cout << std::endl; 
    return 0;
}

// Insertion Sort implementation (dummy for now)
int Sorting::doInsertionSort() {
    return 0;
}

// Merge Sort implementation (dummy for now)
int Sorting::doMergeSort() {
    return 0;
}

// Quick Sort implementation (dummy for now)
int Sorting::doQuickSort() {
    return 0;
}

