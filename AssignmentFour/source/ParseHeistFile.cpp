#include "AssignmentFour/include/ParseHeistFile.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string COMMENT_INDICATOR = "--";

// Split a string based on a delimiter
vector<string> ParseHeistFile::splitString(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Remove comments from the vector
vector<string> ParseHeistFile::doIgnoreComments(vector<string> lines) {
    // Find lines designated as comments
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].find(COMMENT_INDICATOR) != string::npos) {
            lines[i] = "";
        }
    }
    // Return the vector clean of comments
    return lines;
}

// Remove excess spaces from a vector
vector<string> ParseHeistFile::doStripLines(vector<string> lines) {
    // Hold all lines that are not empty
    vector<string> cleanedLines;
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
vector<string> ParseHeistFile::readHeistFile(string newFile) {
    // To hold each line
    vector<string> lines;
    // Read and extract lines
    ifstream file(newFile);
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

ParseHeistFile parse;