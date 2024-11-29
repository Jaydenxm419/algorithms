// Spice Heist Files
#include "include/Spice.h"
#include "include/Knapsack.h"
#include "include/SpiceHeist.h"
#include "include/Sorting.h"
#include <vector>
#include <string>

// Directed Graph files
#include "include/DirectedGraph.h"
#include "include/ParseHeistFile.h"
#include "include/BuildDirectedGraph.h"
#include "include/ProjectConstants.h"
#include "include/Search.h"
using namespace std;

// Contains steps for the spice heist
SpiceHeist doHeist;
// Sorts the spices
Sorting sorting;

// Complete the directed graph exercise
void completeDirectedGraphExerice() {
    // Read the file
    vector<string> contents = parse.readHeistFile(DIRECTED_GRAPH_FILE);
    // Build the graphs
    vector<DirectedGraph*> graphs = build.buildGraph(contents);
    // Find the shortest to all vertices
    doSearch.findShortestPath(graphs);
}

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
    // Complete the directed graph task
    completeDirectedGraphExerice();
    return 0;
}