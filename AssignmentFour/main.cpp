#include "include/Spice.h"
#include "include/Knapsack.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

const string SPICE_FILE = "AssignmentFour/spice.txt";
const string SPICE_KEY_WORD = "spice";
const string KNAPSACK_KEY_WORD = "knapsack";
const string COMMENT_INDICATOR = "--";

// Split a string based on a delimiter
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Create a new spice object
Spice* newSpice(std::string instructions) {
    // Character to split separated command data
    char delimeter = ';';
    // To store separated command data
    std::vector<std::string> splitInstructions = splitString(instructions, delimeter);
    // Character to split within the command data
    delimeter = '=';
    // To store individual spice characteristics
    std::vector<std::string> splitLineInstructions;
    // To save the relevant command data
    std::vector<std::string> characteristics;
    // Define the relevant command data
    std::string name, price, quantity, characteristic;
    // Iterate through each spice instruction
    for (int i = 0; i < splitInstructions.size(); i++) {
        // Ignore everything before an '='
        splitLineInstructions = splitString(splitInstructions[i], delimeter);
        // Store characteristic information following '='
        characteristic = splitLineInstructions[1];
        // Remove excess whitespace
        characteristic.erase(std::remove_if(characteristic.begin(),
        characteristic.end(), ::isspace), characteristic.end());
        // Add the characteristic to the vector
        characteristics.push_back(characteristic);
        // Release the string pointer
        characteristic.clear();
    }
    // Create a spice object
    name = characteristics[0];
    price = characteristics[1];
    quantity = characteristics[2];
    Spice *spice = new Spice(name, quantity, price);
    // Return the object
    return spice;
}

// Create new knapsack objects from instruction file
Knapsack* newKnapsack(std::string instructions) {
    // Define what to split on
    char delimeter = '=';
    // Divide the string on '='
    std::vector<std::string> splitInstructions = splitString(instructions, delimeter);
    // Split on ';'
    delimeter = ';';
    splitInstructions = splitString(splitInstructions[1], delimeter);
    // Hold capacity of knapsack
    std::string capacity;
    for (int i = 0; i < splitInstructions.size(); i++) {
        // Get the capacity value
        capacity = splitInstructions[i];
        // Remove whitespace
        capacity.erase(std::remove_if(capacity.begin(),
        capacity.end(), ::isspace), capacity.end());
    } 
    Knapsack *knapsack = new Knapsack(capacity);
    // Return the knapsack object
    return knapsack;
}

// Remove comments from the vector
std::vector<std::string> doIgnoreComments(std::vector<std::string> lines) {
    // Find lines designated as comments
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].find(COMMENT_INDICATOR) != std::string::npos) {
            lines[i] = "";
        }
    }
    // Return the vector clean of comments
    return lines;
}

// Remove excess spaces from a vector
std::vector<std::string> doStripLines(std::vector<std::string> lines) {
    // Hold all lines that are not empty
    std::vector<std::string> cleanedLines;
    // Find lines with data
    for (int i = 0; i < lines.size(); i++) {
        if(lines[i] != "") {
            cleanedLines.push_back(lines[i]);
        }
    }
    // Return the vector clean of empty lines
    return cleanedLines;
}

// Read spice file
std::vector<std::string> readHeistFile() {
    // To hold each line
    std::vector<std::string> lines;
    // Read and extract lines
    ifstream file(SPICE_FILE);
    string line;
    if (file) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    // Strip the text of comments
    lines = doIgnoreComments(lines);
    // Strip the text of empty lines
    lines = doStripLines(lines);
    return lines;
}

// Get the different spices
std::vector<Spice*> getSpices(std::string spiceStr) {
    // Get the spice information from the file
    std::vector<std::string> lines = readHeistFile();
    std::vector<Spice*> spices;
    // Iterate to find spice commands
    for (int i = 0; i < lines.size(); i++) {
        // If line is a spice command
        if (lines[i].find(spiceStr) != std::string::npos) {
           Spice *spice = newSpice(lines[i]);
           // Add the spice object to the vector of spices
           spices.push_back(spice);
        } 
    }
    // Return the different spice objects
    return spices;
}

// Get the different knapsacks
std::vector<Knapsack*> getKnapsacks(std::string knapsackStr) {
    // Get the spice information from the file
    std::vector<std::string> lines = readHeistFile();
    std::vector<Knapsack*> knapsacks;
    // Iterate to find knapsack commands
    for (int i = 0; i < lines.size(); i++) {
        // If the line is a knapsack command
        if (lines[i].find(knapsackStr) != std::string::npos) {
           Knapsack *knapsack = newKnapsack(lines[i]);
           // Add the knapsack objects to the vector of knapsacks
           knapsacks.push_back(knapsack);
        }
    }
    // Return the knapsack objects
    return knapsacks;
}

// Merge many arrays for Merge Sort
std::vector<Spice*> mergeSpices(std::vector<Spice*> spices, std::vector<Spice*> leftElements, std::vector<Spice*> rightElements) {
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
std::vector<Spice*> doMergeSort(std::vector<Spice*> spices) {
    // Get the size of the current vector
    int size = spices.size();
    // Return the base case
    if (size <= 1) {
        return spices;  
    }
    int middle = size / 2; // Determine the middle index
    std::vector<Spice*> leftElements;  // Define the left array bound
    std::vector<Spice*> rightElements; // Define the right array bound
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
    std::vector<Spice*> mergedSpices = mergeSpices(spices, leftElements, rightElements);
    return mergedSpices;
}

// Calculate the correct combination to maximize a knapsacks value
void getHighestValue(std::vector<Spice*> spices, std::vector<Knapsack*> knapsacks) {
    // Iterate through different knapsacks
    while(!knapsacks.empty()) {
        Knapsack* currentKnapsack = knapsacks.back();
        int knapsackCapacity = std::stoi(currentKnapsack->getCapacity());
        // The total value of a knapsack
        int knapsackPrice = 0;
        // Hold the spice names within a knapsack
        std::vector<std::string> spiceNames;
        // Iterate until the knapsack is full
        int currentSpiceIndex = 0;
        while(knapsackCapacity != 0 && currentSpiceIndex < spices.size()) {
            // The quantity of a given spice
            int spiceQuantity = std::stoi(spices[currentSpiceIndex]->getQuantity());
            // Hold value for fractional spice quantity
            int fractionOfSpice = 0;
            // The capacity of the knapsack is less than the total amount of a given spice
            if (knapsackCapacity < spiceQuantity) {
                // Get the price of leftover spice that fills up the knapsack
                fractionOfSpice = spiceQuantity - knapsackCapacity;
                knapsackCapacity = knapsackCapacity - fractionOfSpice;
                knapsackPrice += fractionOfSpice * std::stoi(spices[currentSpiceIndex]->getUnitPrice());
                spiceNames.push_back(std::to_string(fractionOfSpice) + " scoop of " + spices[currentSpiceIndex]->getName());
            } else { // The total spice quantity is less than the knapsack capacity
                // Get the price of the next spice addition to the knapsack
                knapsackCapacity = knapsackCapacity - spiceQuantity;
                knapsackPrice += spiceQuantity * std::stoi(spices[currentSpiceIndex]->getUnitPrice());
                spiceNames.push_back(std::to_string(spiceQuantity) + " scoop of " + spices[currentSpiceIndex]->getName());
            }
            currentSpiceIndex++;
        }
        // Build a string containing all spices and number of scoops
        std::string string;
        for (int i = 0; i < spiceNames.size(); i++) {
            string += spiceNames[i] + ", ";
        }
        std::cout << "Knapsack of capacity " << currentKnapsack->getCapacity() << " is worth " << knapsackPrice << " quatloos " <<  "and contains " << string << std::endl;
        // Remove the knapsack
        knapsacks.pop_back();
    }
}

// Complete the spice task
void completeSpiceExercise() {
    // Get all spice objects
    std::vector<Spice*> spices = getSpices(SPICE_KEY_WORD);
    // Sort objects by unit price
    std::vector<Spice*> sortedSpices = doMergeSort(spices);
    // Get all knapsack objects
    std::vector<Knapsack*> knapsacks = getKnapsacks(KNAPSACK_KEY_WORD);
    // Calculate the greatest value for each knapsack
    getHighestValue(sortedSpices, knapsacks);

}

// Assignment 4
int main() {
    // Complete the spice task
    completeSpiceExercise();
    return 0;
}