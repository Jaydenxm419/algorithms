#include "Search.h"
#include <string>
#include <iostream>
#include <iomanip>

// Method to do a linear search on an array of items
void Search::doLinearSearch(std::string *items, Stack &stack, int size) {
    int comparisonCount = 0; // Comparison counter for each search
    int totalComparisons = 0; // Total number of comparisons for all searches
    double averageComparisons = 0; // Hold the average number of comparisons for all searches
    // Search for each item in stack in items
    while (!stack.isEmpty()) {  
        std::string item = stack.pop(); // Get next item
        bool found = false; // Default to not found
        // Iterate through items to search for item popped from stack
        for (int i = 0; i < size; i++) {
            comparisonCount++;
            if (items[i] == item) {  
                found = true;
                break;
            }
        }
        // Print if an item is not found in items
        if (!found) {
            std::cout << "Item not found: " << item;
        }
        // Update the total number of comparisons
        totalComparisons = totalComparisons + comparisonCount;
        // Update comparison counter for the next item
        comparisonCount = 0;
    }
    // Compute the average number of searches
    std::cout << "--------------------------------------" << "\n";
    std::cout << "LINEAR SEARCH" << "\n" << "\n";
    averageComparisons = totalComparisons / 42.0; 
    std::cout << std::fixed << std::setprecision(2);  // Set precision to 2 decimal places
    std::cout << "Average Comparisons: " << averageComparisons << "\n";
    std::cout << "--------------------------------------" << "\n";
}

// Method to do a binary search on an array of items
void Search::doBinarySearch(std::string *items, Stack &stack, int size) {
    double comparisonCount = 0; // Comparison counter for each search
    double totalComparisons = 0; // Total number of comparisons for all searches
    double averageComparisons = 0; // Hold the average number of comparisons for all searches
    int midpoint = 0; 
    int startIndex = 0;
    int endIndex = 0;
    bool found = false;
    // Search for all items in the stack
    while(!stack.isEmpty()) {
        std::string item = stack.pop(); // Get the next item
        // Keep track of the focused portion of the array
        midpoint = size / 2; 
        startIndex = 0; 
        endIndex = size - 1; 
        found = false; // By default, the item is not found
        comparisonCount = 0; // Counter to keep track of comparisons
        // Continuously halve the array until the end index is greater than the start index
        while(!found && startIndex <= endIndex) {
            midpoint = startIndex + (endIndex - startIndex) / 2; // Calculate the new midpoint
            comparisonCount++; 
            if (item == items[midpoint]) { // Item was found
                found = true;
            } else if (item < items[midpoint]) { // Focus on the left portion
                endIndex = midpoint - 1;
            } else if (item > items[midpoint]) { // Foucus on the right portion
                startIndex = midpoint + 1;
            }
        }
        totalComparisons += comparisonCount; // Update total comparisons
    }

    std::cout << "BINARY SEARCH" << "\n" << "\n";
    averageComparisons = totalComparisons / 42;
    std::cout << std::fixed << std::setprecision(2);  // Set precision to 2 decimal places
    std::cout << "Average Comparisons: " << averageComparisons << "\n";
    std::cout << "--------------------------------------" << "\n";
}


