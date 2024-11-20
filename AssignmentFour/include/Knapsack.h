#include <string>

class Knapsack {
    private:
        std::string capacity;
        std::string price;
    public:
        Knapsack(const std::string &cap);
        std::string getCapacity();
};