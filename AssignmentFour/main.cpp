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
    // Release the pointers
    name.clear(), price.clear(), quantity.clear();
    splitInstructions.clear();
    splitLineInstructions.clear();
    // Return the object
    return spice;
}

// Create new knapsack objects from instruction file
Knapsack* newKnapsack(std::string instructions) {
    // Define what to split on
    char delimeter = '=';
    // Divide the string on '='
    std::vector<std::string> splitInstructions = splitString(instructions, delimeter);
    delimeter = ';';
    std::string capacity;
    splitInstructions = splitString(splitInstructions[1], delimeter);
    for (int i = 0; i < splitInstructions.size(); i++) {
        capacity = splitInstructions[i];
        capacity.erase(std::remove_if(capacity.begin(),
        capacity.end(), ::isspace), capacity.end());
    } 
    Knapsack *knapsack = new Knapsack(capacity);
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

// Get the different objects
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
    return spices;
}

std::vector<Knapsack*> getKnapsacks(std::string knapsackStr) {
    // Get the spice information from the file
    std::vector<std::string> lines = readSpiceFile();
    std::vector<Knapsack*> knapsacks;
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].find("knapsack") != std::string::npos && knapsackStr == "knapsack") {
           Knapsack *knapsack = newKnapsack(lines[i]);
           // Add the knapsack objects to the vector of knapsacks
           knapsacks.push_back(knapsack);
        }
    }
    return knapsacks;
}

// Complete the spice task
void completeSpiceExercise() {
    // Get all spice objects
    std::string spiceSubStr = "spice";
    std::vector<Spice*> spices = getSpices(spiceSubStr);
    for (int i = 0; i < spices.size(); i++) {
        std::cout << spices[i]->getName() << std::endl;
    }
    // Get all knapsack objects
    std::string knapSubStr = "knapsack";
    std::vector<Knapsack*> knapsacks = getKnapsacks(knapSubStr);
    for (int i = 0; i < knapsacks.size(); i++) {
        std::cout << knapsacks[i]->getCapacity() << std::endl;
    }
}

// Assignment 4
int main() {
    // Complete the spice task
    completeSpiceExercise();
    return 0;
}