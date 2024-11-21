#include "AssignmentFour/include/Spice.h"
#include <iostream>

// Initialize spice name, quanity, and price
Spice::Spice(const std::string &nme, const std::string &quant, const std::string &prc) : name(nme), quantity(quant), price(prc), unitPrice(calculateUnitPrice()) {}

// Get the color of spice
std::string Spice::getName() {
    return name;
}
// Get the quantity of this spice
std::string Spice::getQuantity() {
    return quantity;
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
std::string Spice::getUnitPrice() {
    return unitPrice;
}

void Spice::digSpice(std::string numOfSpice) {
    int newQuantity = std::stoi(quantity) - std::stoi(numOfSpice);
    quantity = newQuantity;
}