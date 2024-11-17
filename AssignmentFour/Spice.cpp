#include "Spice.h"



Spice::Spice(const std::string &nme, const std::string &quant, const std::string &prc) : name(nme), quantity(quant), price(prc) {}

void Spice::setName(std::string name) {
    this.name = name;
}
std::string Spice::getName() {
    return name;
}
void Spice::setQuantity(std::string quantity){
    this.quantity = quantity;
}
std::string Spice::getQuantity() {
    return quantity;
}
void Spice::setPrice(std::string price) {
    this.price = price;
}
std::string Spice::getPrice() {
    return price;
}