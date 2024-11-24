#include <string>
using namespace std;

#ifndef SPICE_H
#define SPICE_H
/* This class represents spices that go into knapsacks in the spice heist */
class Spice {
    private:
        string name;
        string quantity;
        string price;
        string unitPrice;
        int originalQuantity;
    public:
        // Spices on Arrakis have a name, quantity, and a price
        Spice(const string &nme, const string &quant, const string &prc);
        // Returns the name
        string getName();
        // Returns the quantity
        string getQuantity();
        // Returns the price
        string getPrice();
        // Generates the unit price
        string calculateUnitPrice();
        // Returns the unit price
        string getUnitPrice();
        // Update the quantity
        void setQuantity(int quantity);
        // Dig spice from Arrakis
        void digSpice(string numOfSpice);
        // Return the original quantity of spice on Arrakis
        int getOriginalQuantity();
};

#endif 
