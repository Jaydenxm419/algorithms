#include "Spice.h"
#include "Knapsack.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string SPICE_FILE = "AssignmentFour/spice.txt";

// Split a string based on a delimiter
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    // Relieve the pointers
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
    Spice *spice = new Spice(name, price, quantity);
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
    string commentIndicator = "--";
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].find(commentIndicator) != std::string::npos) {
            lines[i] = lines[i + 1];
            lines[i] = "";
        }
    }
    // Return the pruned commands
    return lines;
}

// Remove excess spaces from a vector
std::vector<std::string> doStripLines(std::vector<std::string> lines) {
    std::vector<std::string> cleanedLines;
    for (int i = 0; i < lines.size(); i++) {
        if(lines[i] != "") {
            cleanedLines.push_back(lines[i]);
        }
    }
    return cleanedLines;
}

// Read spice file
std::vector<std::string> readSpiceFile() {
    std::vector<std::string> lines;
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
    std::vector<std::string> lines = readSpiceFile();
    std::vector<Spice*> spices;
    // Iterate to find spice commands
    for (int i = 0; i < lines.size(); i++) {
        // If object value intends on finding spice commands 
        if (lines[i].find("spice") != std::string::npos && spiceStr == "spice") {
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
    std::vector<std::string> lines = readSpiceFile();
    // Hold the different knapsacks
    std::vector<Knapsack*> knapsacks;
    for (int i = 0; i < lines.size(); i++) {
        // If knapsackStr value intends on finding knapsack commands
        if (lines[i].find("knapsack") != std::string::npos && knapsackStr == "knapsack") {
           // Create the object based on the current line
           Knapsack *knapsack = newKnapsack(lines[i]);
           // Add the knapsack objects to the vector of knapsacks
           knapsacks.push_back(knapsack);
        }
    }
    // Return the knapsack objects
    return knapsacks;
}

// Method to merge many arrays for Merge Sort
std::vector<Spice*> mergeSpices(std::vector<Spice*> spices, std::vector<Spice*> leftElements, std::vector<Spice*> rightElements) {
    // Define helper variables for comparison
    int i = 0;
    int left = 0;
    int right = 0;

    // Compare left and right items for merging
    while (left < leftElements.size() && right < rightElements.size()) {
        if (leftElements[left]->getUnitPrice() < rightElements[right]->getUnitPrice()) {
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

std::vector<Spice*> divideSpices(std::vector<Spice*> spices) {
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
    divideSpices(leftElements);  // Handle the left branch
    divideSpices(rightElements);  // Handle the right branch

    // Merge leftItems and rightItems until the full array is rebuilt sorted 
    std::vector<Spice*> mergedSpices = mergeSpices(spices, leftElements, rightElements);

    return spices;
}

// Complete the spice task
void completeSpiceExercise() {
    // Get all spice objects
    std::string spiceSubStr = "spice";
    std::vector<Spice*> spices = getSpices(spiceSubStr);
    std::vector<Spice*> sortedSpices = divideSpices(spices);
    for (int i = 0; i < sortedSpices.size(); i++) {
        std::string unit = sortedSpices[i]->getUnitPrice();
        std::cout << sortedSpices[i]->getName() << " : "<< unit << "\n";
    }
    // Get all knapsack objects
    std::string knapSubStr = "knapsack";
    std::vector<Knapsack*> knapsacks = getKnapsacks(knapSubStr);
}

// Assignment 4
int main() {
    // Complete the spice task
    completeSpiceExercise();
    return 0;
}