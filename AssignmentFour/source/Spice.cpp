#include "AssignmentFour/include/Spice.h"
#include <iostream>

// Initialize spice name, quanity, and price
Spice::Spice(const std::string &nme, const std::string &quant, const std::string &prc) : name(nme), quantity(quant), price(prc), unitPrice(calculateUnitPrice()), originalQuantity(std::stoi(getQuantity())) {}

// Get the color of spice
std::string Spice::getName() {
    return name;
}
// Get the quantity of this spice
std::string Spice::getQuantity() {
    return quantity;
}
// Set the quantity to reset 
void Spice::setQuantity(int quant) {
    quantity = std::to_string(quant);
}
// Get the price of this spice
std::string Spice::getPrice() {
    return price;
}
// Calculate the unit price of this spice
std::string Spice::calculateUnitPrice() {
    int quantity = std::stoi(this->getQuantity());
    int price = std::stoi(this->getPrice());
    float unitPrice = price / quantity;
    return std::to_string(unitPrice);
}
// Return the unit price
std::string Spice::getUnitPrice() {
    return unitPrice;
}
// Remove spice from Arrakis
void Spice::digSpice(std::string numOfSpice) {
    int newQuantity = std::stoi(quantity) - std::stoi(numOfSpice);
    quantity = std::to_string(newQuantity);
}
// Save the original quantity 
int Spice::getOriginalQuantity() {
    return originalQuantity;
}