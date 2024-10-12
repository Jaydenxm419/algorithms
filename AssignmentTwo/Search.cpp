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
    std::cout << "Average number of comparisons: " << averageComparisons << "\n";
    std::cout << "--------------------------------------" << "\n";
}

// Method to do a binary search on an array of items
void Search::doBinarySearch(std::string *items, Stack &stack, int size) {
    int comparisonCount = 0; // Comparison counter for each search
    int totalComparisons = 0; // Total number of comparisons for all searches
    double averageComparisons = 0; // Hold the average number of comparisons for all searches
    int midpoint = size / 2;
    int startIndex = 0;
    int endIndex = size - 1;
    bool found = false;
    while(!stack.isEmpty()) {
        std::string item = stack.pop();
        while(!found) {
            if (item > items[midpoint]) {
                startIndex = midpoint;
            }
        }
    }
}


