#include <string>
#include "AssignmentFour/include/Spice.h"
#include <vector>
class Knapsack {
    private:
        std::string capacity;
        std::vector<Spice*> spices;
    public:
        Knapsack(const std::string &cap);
        std::string getCapacity();
        std::vector<Spice*> getContents();
        void addSpice(Spice *spice);
        std::string getTotalPrice();
};