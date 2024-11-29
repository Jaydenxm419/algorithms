#include "AssignmentFour/include/Knapsack.h"
#include "AssignmentFour/include/Spice.h"
#include <string>
using namespace std;

// Constructor
Knapsack::Knapsack(const string &cap) : capacity(cap), spices() {}

// Return the potential capacity of a knapsack
string Knapsack::getCapacity() {
    return capacity;
}

// Return the spices within a knapsack
vector<Spice*> Knapsack::getContents(){
    return spices;
}

// Add a spice to the knapsack
void Knapsack::addSpice(Spice* spice) {
    spices.push_back(spice);
}

// Calculate the total price of the knapsack
string Knapsack::getTotalPrice() {
    int total = 0;
    for (int i = 0; i < spices.size(); i++) {
        total = total + (stoi(spices[i]->getUnitPrice()) * stoi(spices[i]->getQuantity()));
    }
    return to_string(total);
}
