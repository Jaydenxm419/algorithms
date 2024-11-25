#include "AssignmentFour/include/SpiceHeist.h"
#include "AssignmentFour/include/ParseHeistFile.h"
#include "AssignmentFour/include/Knapsack.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class that contains file parsing methods
const string SPICE_FILE = "AssignmentFour/spice.txt";

// Create a new spice object
Spice* SpiceHeist::newSpice(string instructions) {
    // Character to split separated command data
    char delimeter = ';';
    // To store separated command data
    vector<string> splitInstructions = parse.splitString(instructions, delimeter);
    // Character to split within the command data
    delimeter = '=';
    // Individual spice characteristics
    vector<string> splitLineInstructions;
    vector<string> characteristics;
    string name, price, quantity, characteristic;
    // Iterate through each spice instruction
    for (int i = 0; i < splitInstructions.size(); i++) {
        // Ignore everything before an '='
        splitLineInstructions = parse.splitString(splitInstructions[i], delimeter);
        characteristic = splitLineInstructions[1];
        // Remove excess whitespace
        characteristic.erase(remove_if(characteristic.begin(),
        characteristic.end(), ::isspace), characteristic.end());
        // Add the characteristic to the vector
        characteristics.push_back(characteristic);
        // Release the string pointer
        characteristic.clear();
    }
    // Create a spice object
    name = characteristics[0];
    price = characteristics[1];
    quantity = characteristics[2];
    Spice *spice = new Spice(name, quantity, price);
    // Return the object
    return spice;
}

// Create new knapsack objects from instruction file
Knapsack* SpiceHeist::newKnapsack(string instructions) {
    // Define what to split on
    char delimeter = '=';
    // Divide the string on '='
    vector<string> splitInstructions = parse.splitString(instructions, delimeter);
    // Split on ';'
    delimeter = ';';
    splitInstructions = parse.splitString(splitInstructions[1], delimeter);
    // Hold capacity of knapsack
    string capacity;
    for (int i = 0; i < splitInstructions.size(); i++) {
        // Get the capacity value
        capacity = splitInstructions[i];
        // Remove whitespace
        capacity.erase(remove_if(capacity.begin(),
        capacity.end(), ::isspace), capacity.end());
    } 
    Knapsack *knapsack = new Knapsack(capacity);
    // Return the knapsack object
    return knapsack;
}

// Get the different spices
vector<Spice*> SpiceHeist::getSpices(string spiceStr) {
    // Get the spice information from the file
    vector<string> lines = parse.readHeistFile(SPICE_FILE);
    vector<Spice*> spices;
    // Iterate to find spice commands
    for (int i = 0; i < lines.size(); i++) {
        // If line is a spice command
        if (lines[i].find(spiceStr) != string::npos) {
           Spice *spice = newSpice(lines[i]);
           // Add the spice object to the vector of spices
           spices.push_back(spice);
        } 
    }
    // Return the different spice objects
    return spices;
}

// Get the different knapsacks
vector<Knapsack*> SpiceHeist::getKnapsacks(string knapsackStr) {
    // Get the spice information from the file
    vector<string> lines = parse.readHeistFile(SPICE_FILE);
    vector<Knapsack*> knapsacks;
    // Iterate to find knapsack commands
    for (int i = 0; i < lines.size(); i++) {
        // If the line is a knapsack command
        if (lines[i].find(knapsackStr) != string::npos) {
           Knapsack *knapsack = newKnapsack(lines[i]);
           // Add the knapsack objects to the vector of knapsacks
           knapsacks.push_back(knapsack);
        }
    }
    // Return the knapsack objects
    return knapsacks;
}

// Build a string for heist output
void SpiceHeist::buildHeistOutput(Knapsack* currentKnapsack) {
    // Get knapsack details
    const vector<Spice*> contents = currentKnapsack->getContents();
    int currentKnapsackSize = contents.size();
    string knapsackCapacity = currentKnapsack->getCapacity();
    string totalPrice = currentKnapsack->getTotalPrice();

    // Prepare output
    ostringstream output;
    output << "Knapsack of capacity " << knapsackCapacity 
           << " is worth " << totalPrice 
           << " and contains ";

    // Append spices
    for (int i = 0; i < currentKnapsackSize; ++i) {
        output << contents[i]->getQuantity() << " scoops of " 
               << contents[i]->getName();
        if (i < currentKnapsackSize - 1) {
            output << ", ";
        }
    }
    // Print the result
    cout << output.str() << endl;
}

// Calculate the correct combination to maximize a knapsacks value
void SpiceHeist::getHighestValue(vector<Spice*> spices, vector<Knapsack*> knapsacks) {
    // Iterate through different knapsacks
    while(!knapsacks.empty()) {
        Knapsack* currentKnapsack = knapsacks.back();
        int knapsackCapacity = stoi(currentKnapsack->getCapacity());
        // The total value of a knapsack
        int knapsackPrice = 0;
        // Hold the spice names within a knapsack
        vector<string> spiceNames;
        // Iterate until the knapsack is full
        int currentSpiceIndex = 0;
        while(knapsackCapacity != 0 && currentSpiceIndex < spices.size()) {
            // The quantity of a given spice
            int spiceQuantity = stoi(spices[currentSpiceIndex]->getQuantity());
            // Hold value for fractional spice quantity
            int fractionOfSpice = 0;
            // The capacity of the knapsack is less than the total amount of a given spice
            if (knapsackCapacity < spiceQuantity) {
                // Get the price of leftover spice that fills up the knapsack
                fractionOfSpice = spiceQuantity - knapsackCapacity;
                knapsackCapacity = knapsackCapacity - fractionOfSpice;
                knapsackPrice = fractionOfSpice * stoi(spices[currentSpiceIndex]->getUnitPrice());
                // Spice object representing a fraction of the original added to the knapsack
                Spice *spice = new Spice(spices[currentSpiceIndex]->getName(), to_string(fractionOfSpice), to_string(knapsackPrice));
                // Add spice to the knapsack
                currentKnapsack->addSpice(spice);
                // Dig spice from arrakis
                spices[currentSpiceIndex]->digSpice(spice->getQuantity());
            } else { 
                // Get the price of the next spice addition to the knapsack
                knapsackCapacity = knapsackCapacity - spiceQuantity;
                knapsackPrice = spiceQuantity * stoi(spices[currentSpiceIndex]->getUnitPrice());
                // Spice object added to the knapsack
                Spice *spice = new Spice(spices[currentSpiceIndex]->getName(), to_string(spiceQuantity), to_string(knapsackPrice));
                // Add psice to the knapsack
                currentKnapsack->addSpice(spice);
                // Dig spice from arrakis
                spices[currentSpiceIndex]->digSpice(to_string(spiceQuantity));
            }
            currentSpiceIndex++;
        }
        // Build a string containing all spices and number of scoops
        buildHeistOutput(currentKnapsack);

        // Reset the spices quantities for the next knapsack
        for (int i = 0; i < spices.size(); i++) {
            // Print the amount of spice still on Arrakis
            cout << "Arrakis has " << spices[i]->getQuantity() << " of " << spices[i]->getName() << " spice unclaimed" << "\n";
            spices[i]->setQuantity(spices[i]->getOriginalQuantity());
        }
        // Remove the knapsack
        knapsacks.pop_back();
    }
}