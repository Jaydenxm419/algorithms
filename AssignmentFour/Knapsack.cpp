#include "Knapsack.h"
#include <string>

// Constructor
Knapsack::Knapsack(const std::string &cap) : capacity(cap) {}
std::string Knapsack::getCapacity() {
    return capacity;
}