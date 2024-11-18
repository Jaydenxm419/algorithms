#include "Spice.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

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
void newSpice(std::string instructions) {
    // Character that is being split on
    char delimeter = ';';
    // Vector for the line
    std::vector<std::string> splitInstructions = splitString(instructions, delimeter);

    for (int i = 0; i < splitInstructions[i].size(); i++) {
        std::vector<std::string> splitLineInstructions = splitString(splitInstructions[i], ' ');
        // for (int j = 0; j < splitLineInstructions[j].size(); j++) {
            std::cout << splitInstructions[i];
        // }
    }
    
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

// Remove excess spaces from the vector
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

// Complete the spice task
void completeSpiceExercise() {
    // Get the spice instructions
    std::vector<std::string> lines = readSpiceFile();
    std::string spiceSubStr = "spice";
    std::string knapsackSubStr = "knapsack";
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].find("spice") != std::string::npos) {
           newSpice(lines[i]);
           std::cout << std::endl;
        } 
    }
}

// Assignment 4
int main() {
    // Complete the spice task
    completeSpiceExercise();
    return 0;
}