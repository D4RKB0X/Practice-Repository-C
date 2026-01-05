#include <iostream>
#include <string>
#include <memory>

class Unit {
    private:
        std::string name;
        int gold, lumber, food;
    
    public:
        Unit(const std::string& n, int g, int l, int f)
            : name(n), gold(g), lumber(l), food(f) {}
    
        int getFoodCost() const { return food; }
    
        void displayInfo() const {
            std::cout << "Name: " << name
                      << "\nGold: " << gold
                      << "\nLumber: " << lumber
                      << "\nFood: " << food << "\n";
        }
};

class MoonWell {
    private:
        int foodCap;
    
    public:
        MoonWell(int cap) : foodCap(cap) {}
    
        bool canSpawnUnit(int unitFood) const {
            return unitFood <= foodCap;
        }
    
        void useFood(int unitFood) {
            if (canSpawnUnit(unitFood)) {
                foodCap -= unitFood;
                std::cout << "Unit spawned! | Food remaining: " << foodCap << "\n";
            } else {
                std::cout << "Not enough food to spawn this unit!\n";
            }
        }
    
        void displayCap() const {
            std::cout << "Current food cap: " << foodCap << "\n";
        }
};

int main() {
    
    MoonWell well(5);
    well.displayCap();
    std::cout << "--------------------\n";

    auto archer = std::make_unique<Unit>("Archer", 50, 25, 2);

    if (well.canSpawnUnit(archer->getFoodCost())) {
        well.useFood(archer->getFoodCost());
        archer->displayInfo();
    }

    std::cout << "--------------------\n";

    auto archer2 = std::make_unique<Unit>("Archer", 50, 25, 4);
    if (well.canSpawnUnit(archer2->getFoodCost())) {
        well.useFood(archer2->getFoodCost());
        archer2->displayInfo();
    }
    else {
        std::cout << "Cannot spawn second Archer: food cap exceeded.\n";
    }

    return 0;
}
