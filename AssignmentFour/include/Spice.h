#include <string>

#ifndef SPICE_H
#define SPICE_H
class Spice {
    private:
        std::string name;
        std::string quantity;
        std::string price;
        std::string unitPrice;
        int originalQuantity;
    public:
        Spice(const std::string &nme, const std::string &quant, const std::string &prc);
        std::string getName();
        std::string getQuantity();
        void setQuantity(int quantity);
        std::string getPrice();
        std::string calculateUnitPrice();
        std::string getUnitPrice();
        void digSpice(std::string numOfSpice);
        int getOriginalQuantity();
};

#endif 
