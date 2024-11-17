#include <string>

class Spice {
    private:
        std::string name;
        std::string quantity;
        std::string price;
    public:
        Spice(const std::string &nme, const std::string &quant, const std::string &prc);
        void setName(std::string name);
        std::string getName();
        void setQuantity(std::string quantity);
        std::string getQuantity();
        void setPrice(std::string price);
        std::string getPrice();
}