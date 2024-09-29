#include "sorting.h"
#include <string>

// Selection sorting algorithm
int Sorting::doSelectionSort(std::string *items, int size)
{
    int comparisonCount = 0; // Counter to verify average sort comparisons

    // Iterate through magic items
    for (int i = 0; i < size; ++i)
    {
        int minIndex = i; // Initialize the minimum index to the current index
        std::string min = items[i]; // Initialize the minimum string value to the current string

        // Iterate through magic items for every item following the current index of i
        for (int j = i + 1; j < size; j++) // Start from i + 1
        {
            comparisonCount++;
            // Compare each string to the current minimum
            if (items[j] < min)
            {
                min = items[j]; // Define the new minimum
                minIndex = j;   // Define location of the new minimum
            }
        }
        
        // Swap the current string with the minimum string after all strings were compared
        std::string temp = items[i];
        items[i] = items[minIndex];
        items[minIndex] = temp;
    }
    
    for (int k = 0; k < size; ++k)
    {
        std::cout << items[k] << "\n"; // Print the items
    }
    std::cout << "Comparison Count: " << comparisonCount << std::endl;
    return 0;
}


// Insertion Sort 
int Sorting::doInsertionSort()
{
    return 0;
}

// Merge Sort 
int Sorting::doMergeSort()
{
    return 0;
}

// Quick Sort 
int Sorting::doQuickSort()
{
    return 0;
}
// Knuth Shuffle
std::string* Sorting::doKnuthShuffle(std::string *items, int size)
{
    // Iterate through the array backwards
    for (int i = size - 1; i > 0; i--)
    {
        int randomIndex = std::rand() % (i + 1); // Generate random index
        std::string temp = items[i]; // Temporary variable to store the current index
        items[i] = items[randomIndex]; // Swap current index with random index
        items[randomIndex] = temp; // Complete the swap
    }
    return items; // Return the pointer to the same array
}
