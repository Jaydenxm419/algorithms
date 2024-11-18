#include "Spice.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string SPICE_FILE = "AssignmentFour/spice.txt";

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
    // Print the ouput
    for (int i = 0; i < lines.size(); i++) {
        std::cout << lines[i] << "\n";
    }
}

// Assignment 4
int main() {
    // Complete the spice task
    completeSpiceExercise();
    return 0;
}