#include "sorting.h"
#include <string>

/** This file contains all method calls for different sorting algortihms 
 * @author Jayden Melendez
 * @date October 2nd, 2024
*/

// Constructor
Sorting::Sorting() {
    comparisonCounter = 0; // Counting the number of comparisons for each sort
}

// Selection Sort
int Sorting::doSelectionSort(std::string *items, int size) {
    // Iterate through magic items
    for (int i = 0; i < size; ++i) {

        int minIndex = i; // Minimum starts at current index          
        std::string min = items[i]; // Minimum value starts as the current value at the current index
        // Iterate through magic items for every item following the current index of i
        for (int j = i + 1; j < size; j++) {   
            comparisonCounter++; // Increment the comparison
            // Compare each string to the current minimum
            if (items[j] < min) {
                min = items[j]; // Define the new minimum
                minIndex = j;   // Define location of the new minimum
            }
        }
        // Swap current string with the smallest string found
        std::string temp = items[i];
        items[i] = items[minIndex];
        items[minIndex] = temp;
    }
    return 0;
}

// Insertion Sort
int Sorting::doInsertionSort(std::string *items, int size) {  
    // Iterate through magic items array
    for (int i = 1; i < size; i++) {
        std::string currentWord = items[i]; // Current word in the first unsorted element
        int j; // Hold value for insertion                              
        // Compare current word with sorted elements until it's smaller        
        for (j = i - 1; j >= 0 && items[j] > currentWord; j--) {
            comparisonCounter++; // Increment the comparison
            items[j + 1] = items[j]; // Shift the current element to the right
        }
        items[j + 1] = currentWord; // Insert the current word at the returned index
    }
    return 0;
}

// Merge Sort
int Sorting::doMergeSort(std::string *items, int size) {
    // Return the base case
    if (size <= 1) {
        return 0;  
    }
    int middle = size / 2; // Determine the middle index
    std::string *leftItems = new std::string[middle]; // Define the left array bound
    std::string *rightItems = new std::string[size - middle]; // Define the right array bound

    // Populate left items from the left side of items
    for (int i = 0; i < middle; i++) {
        leftItems[i] = items[i];  // Add the items on the left to the left array
    }
    // Populate right items from the right side of items
    for (int i = 0; i < size - middle; i++) {
        rightItems[i] = items[i + middle];  // Add the items on the right to the right array
    }
    // Recursively call method until base case is reached
    doMergeSort(leftItems, middle);  // Handle the left branch
    doMergeSort(rightItems, size - middle);  // Handle the right branch

    // Merge leftItems and rightItems until the full array is rebuilt sorted 
    std::string* mergedItems = doMerge(items, leftItems, rightItems, middle, size - middle);

    // Open up pointers
    delete[] leftItems;
    delete[] rightItems;

    return 0;
}

// Method to merge many arrays for Merge Sort
std::string* Sorting::doMerge(std::string *items, std::string *leftItems, std::string *rightItems, int leftSize, int rightSize) {
    // Define helper variables for comparison
    int i = 0;
    int left = 0;
    int right = 0;

    // Compare left and right items for merging
    while (left < leftSize && right < rightSize) {
        comparisonCounter++; // Increment the comparison counter
        if (leftItems[left] < rightItems[right]) {
            items[i] = leftItems[left];
            left++;
        } else {
            items[i] = rightItems[right];
            right++;
        }
        i++;
    }

    // Handle remaining elements from leftItems
    while (left < leftSize) {
        items[i] = leftItems[left];
        left++;
        i++;
    }

    // Handle remaining elements from rightItems
    while (right < rightSize) {
        items[i] = rightItems[right];
        right++;
        i++;
    }

    return items;  // Return the pointer to the merged array
}

int Sorting::setPartition(std::string *items, int start, int end) {
    std::string temp = "";  // Temp variable for swapping
    std::string pivotValue = items[end];  // Pivot is the last element
    int i = start - 1;  // Helper index starts before the first element

    // Iterate through to the second last element
    for (int j = start; j < end; j++) {
        comparisonCounter++;
        if (items[j] <= pivotValue) {
            i++;  // Increment helper index
            // Swap items[i] and items[j]
            temp = items[i];
            items[i] = items[j];
            items[j] = temp;
        }
    }
    // Place the pivot in its correct position
    temp = items[i + 1];
    items[i + 1] = items[end];
    items[end] = temp;
    return i + 1;  // Return pivot position
}

int Sorting::doQuickSort(std::string *items, int start, int end) {
    if (start < end) {
        int partition = setPartition(items, start, end);  // Partition the array
        doQuickSort(items, start, partition - 1);  // Recursively sort the left part
        doQuickSort(items, partition + 1, end);  // Recursively sort the right part
    }
    return 0;
}



// Knuth Shuffle
std::string *Sorting::doKnuthShuffle(std::string *items, int size) {
    // Iterate through the array backwards
    for (int i = size - 1; i > 0; i--)
    {
        int randomIndex = std::rand() % (i + 1); // Generate random number for index
        // Swapping
        std::string temp = items[i]; 
        items[i] = items[randomIndex]; 
        items[randomIndex] = temp; 
    }
    return items; // Return the pointer to the same array
}
