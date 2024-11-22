#include <string>
#include <vector>
#include "AssignmentFour/include/Spice.h"
#include "AssignmentFour/include/Knapsack.h"
using namespace std;

#ifndef SPICEHEIST_H
#define SPICEHEIST_H
/* This class contains methods that complete a spice hesit */

class SpiceHeist {
    public:
        // Returns a spice object based on an instruction line from the spice heist file
        Spice* newSpice(string instructions);
        // Returns a knapsack object based on an instruction line from the spice heist file
        Knapsack* newKnapsack(string instructions);
        // Return new spices in a vector
        vector<Spice*> getSpices(string spiceStr); 
        // Return new knapsacks in a vector
        vector<Knapsack*> getKnapsacks(string knapsackStr);
        // Build a string for the ouput
        void buildHeistOutput(Knapsack* currentKnapsack);
        // Determine the greatest value in a knapsack
        void getHighestValue(vector<Spice*> spices, vector<Knapsack*> knapsacks);
};

#endif