#include "AssignmentFour/include/Knapsack.h"
#include "AssignmentFour/include/Spice.h"
#include <string>

// Constructor
Knapsack::Knapsack(const std::string &cap) : capacity(cap), spices() {}

// Return the potential capacity of a knapsack
std::string Knapsack::getCapacity() {
    return capacity;
}
// Return the spices within a knapsack
std::vector<Spice*> Knapsack::getContents(){
    return spices;
}
// Add a spice to the knapsack
void Knapsack::addSpice(Spice* spice) {
    spices.push_back(spice);
}
// Calculate the total price of the knapsack
std::string Knapsack::getTotalPrice() {
    int total = 0;
    for (int i = 0; i < spices.size(); i++) {
        total = total + (std::stoi(spices[i]->getUnitPrice()) * std::stoi(spices[i]->getQuantity()));
    }
    return std::to_string(total);
}
