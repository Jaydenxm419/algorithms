#include <string>
class Knapsack {
    private:
        std::string capacity;
    public:
        Knapsack(const std::string &cap);
        std::string getCapacity();
};