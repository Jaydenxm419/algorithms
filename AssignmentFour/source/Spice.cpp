#include "AssignmentFour/include/Spice.h"
#include <iostream>
#include <string>
using namespace std;

// Initialize spice name, quanity, and price
Spice::Spice(const string &nme, const string &quant, const string &prc) : name(nme), quantity(quant), price(prc), unitPrice(calculateUnitPrice()), originalQuantity(stoi(getQuantity())) {}

// Get the color of spice
string Spice::getName() {
    return name;
}
// Get the quantity of this spice
string Spice::getQuantity() {
    return quantity;
}
// Set the quantity to reset 
void Spice::setQuantity(int quant) {
    quantity = to_string(quant);
}
// Get the price of this spice
string Spice::getPrice() {
    return price;
}
// Calculate the unit price of this spice
string Spice::calculateUnitPrice() {
    int quantity = stoi(this->getQuantity());
    int price = stoi(this->getPrice());
    float unitPrice = price / quantity;
    return to_string(unitPrice);
}
// Return the unit price
string Spice::getUnitPrice() {
    return unitPrice;
}
// Remove spice from Arrakis
void Spice::digSpice(string numOfSpice) {
    int newQuantity = stoi(quantity) - stoi(numOfSpice);
    quantity = to_string(newQuantity);
}
// Save the original quantity 
int Spice::getOriginalQuantity() {
    return originalQuantity;
}