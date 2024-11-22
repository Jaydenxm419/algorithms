#include "AssignmentFour/include/Sorting.h"
#include <vector>
#include <string>
using namespace std;

// Merge many arrays for Merge Sort
vector<Spice*> Sorting::mergeSpices(vector<Spice*> spices, vector<Spice*> leftElements, vector<Spice*> rightElements) {
    // Define helper variables for comparison
    int i = 0;
    int left = 0;
    int right = 0;
    // Compare left and right items for merging from greatest to least
    while (left < leftElements.size() && right < rightElements.size()) {
        // Merge together based on unit price
        if (leftElements[left]->getUnitPrice() > rightElements[right]->getUnitPrice()) {
            spices[i] = leftElements[left];
            left++;
        } else {
            spices[i] = rightElements[right];
            right++;
        }
        i++;
    }
    // Handle remaining elements from leftItems
    while (left < leftElements.size()) {
        spices[i] = leftElements[left];
        left++;
        i++;
    }
    // Handle remaining elements from rightItems
    while (right < rightElements.size()) {
        spices[i] = rightElements[right];
        right++;
        i++;
    }
    return spices;  // Return the pointer to the merged array
}

// Merge sort algorithm
vector<Spice*> Sorting::doMergeSort(vector<Spice*> spices) {
    // Get the size of the current vector
    int size = spices.size();
    // Return the base case
    if (size <= 1) {
        return spices;  
    }
    int middle = size / 2; // Determine the middle index
    vector<Spice*> leftElements;  // Define the left array bound
    vector<Spice*> rightElements; // Define the right array bound
    // Populate left items from the left side of items
    for (int i = 0; i < middle; i++) {
        leftElements.push_back(spices[i]); // Add the items on the left to the left array
    }
    // Populate right items from the right side of items
    for (int i = 0; i < size - middle; i++) {
        rightElements.push_back(spices[i + middle]);
    }
    // Recursively call method until base case is reached
    leftElements = doMergeSort(leftElements);  // Handle the left branch
    rightElements = doMergeSort(rightElements);  // Handle the right branch
    // Merge leftItems and rightItems until the full array is rebuilt sorted 
    vector<Spice*> mergedSpices = mergeSpices(spices, leftElements, rightElements);
    return mergedSpices;
}