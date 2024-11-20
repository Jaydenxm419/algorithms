#include "AssignmentFour/include/Knapsack.h"
#include <string>

// Constructor
Knapsack::Knapsack(const std::string &cap) : capacity(cap), price() {}
std::string Knapsack::getCapacity() {
    return capacity;
}
