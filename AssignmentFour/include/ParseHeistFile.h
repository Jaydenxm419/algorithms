#include <vector>
#include <string>
using namespace std;

#ifndef PARSEHEISTFILE_H
#define PARSEHEISTFILE_H
/* This class contains methods that parse text from the spice heist text file */

class ParseHeistFile {
    public:
        // Split a string based on the delimiter
        vector<string> splitString(const string& str, char delimiter);
        // Ignore the comment lines in a text file
        vector<string> doIgnoreComments(std::vector<string> lines);
        // Strip single text lines of spaces
        vector<string> doStripLines(std::vector<string> lines);
        // Returns the cleaned lines in a text file as a vector
        vector<string> readHeistFile();
};

#endif