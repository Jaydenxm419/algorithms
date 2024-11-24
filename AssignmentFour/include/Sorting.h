#include <vector>
#include <string>
#include "AssignmentFour/include/Spice.h"
using namespace std;

#ifndef SORTING_H
#define SORTING_H
/* This class contains methods that sort spices based their unit value */

class Sorting {
    public:
        // Helper merger
        vector<Spice*> mergeSpices(vector<Spice*> spices, vector<Spice*> leftElements, vector<Spice*> rightElements);
        // Returns a sorted vector of spices based on their unit value
        vector<Spice*> doMergeSort(vector<Spice*> spices);
};

#endif