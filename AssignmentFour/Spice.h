#include <string>

class Spice {
    private:
        std::string name;
        std::string quantity;
        std::string price;
    public:
        Spice(const std::string &nme, const std::string &quant, const std::string &prc);
        std::string getName();
        std::string getQuantity();
        std::string getPrice();
        std::string getUnitPrice();
};