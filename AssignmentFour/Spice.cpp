#include "Spice.h"
#include <iostream>

// Initialize spice name, quanity, and price
Spice::Spice(const std::string &nme, const std::string &quant, const std::string &prc) : name(nme), quantity(quant), price(prc) {}

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
std::string Spice::getUnitPrice() {
    int quantity = std::stoi(this->getQuantity());
    int price = std::stoi(this->getPrice());
    float unitPrice = quantity / price;
    return std::to_string(unitPrice);
}
