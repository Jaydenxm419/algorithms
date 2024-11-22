#include <string>
#include <vector>
#include "AssignmentFour/include/Spice.h"
using namespace std;

#ifndef KNAPSACK_H
#define KNAPSACK_H
/* This class represents a knapsack that can hold a finite number of spices in a spice heist */

class Knapsack {
    private:
        string capacity;
        vector<Spice*> spices;
    public:
        // Take in the capacity of the knapsack
        Knapsack(const std::string &cap);
        // Returns the original capacity of the knapsack
        string getCapacity();
        // Returns the current total price of the spices in the knapsack
        string getTotalPrice();
        // Returns the spices in the knapsack
        vector<Spice*> getContents();
        // Adds a spice to the knapsack
        void addSpice(Spice *spice);
};

#endif