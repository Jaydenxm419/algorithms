#include "include/Spice.h"
#include "include/Knapsack.h"
#include "include/SpiceHeist.h"
#include "include/Sorting.h"
#include <string>
using namespace std;

// Contains steps for the spice hesit
SpiceHeist doHeist;
// Sorts the spices
Sorting sorting;

const string SPICE_KEY_WORD = "spice";
const string KNAPSACK_KEY_WORD = "knapsack";

// Complete the spice task
void completeSpiceExercise() {
    // Get all spice objects
    vector<Spice*> spices = doHeist.getSpices(SPICE_KEY_WORD);
    // Sort objects by unit price
    vector<Spice*> sortedSpices = sorting.doMergeSort(spices);
    // Get all knapsack objects
    vector<Knapsack*> knapsacks = doHeist.getKnapsacks(KNAPSACK_KEY_WORD);
    // Calculate the greatest value for each knapsack
    doHeist.getHighestValue(sortedSpices, knapsacks);

}

// Assignment 4
int main() {
    // Complete the spice task
    completeSpiceExercise();
    return 0;
}