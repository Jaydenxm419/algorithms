#include <string>
class Knapsack {
    private:
        std::string capacity;
        std::string id;
    public:
        Knapsack(const std::string &cap);
        std::string getCapacity();
};