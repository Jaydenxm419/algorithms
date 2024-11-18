#include "Spice.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string SPICE_FILE = "AssignmentFour/spice.txt";

// Read spice file
void readSpiceFile() {
    std::vector<std::string> lines;
    ifstream file(SPICE_FILE);
    string line;
    if (file) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }

    for (int i = 0; i < lines.size(); i++) {
        std::cout << lines[i] << "\n";
    }
}

// Main method for assignment 4
int main() {
    readSpiceFile();
    return 0;
}