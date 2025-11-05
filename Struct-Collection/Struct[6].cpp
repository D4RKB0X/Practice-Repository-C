#include <iostream>
#include <string>
#include <vector>

struct Unit {
    std::string name;
    int health = 0;
    
    Unit() = default;
    Unit(std::string n, int h) : name(n), health(h) {};
};

void printUnit(const Unit* u) {
    std::cout << "Name: " << u->name << " | Health: " << u->health << '\n';
}

void healUnit(Unit& u, int healAmount) {
    u.health += healAmount;
}

int main() {
    
    std::vector<Unit> valueUnit;
    valueUnit.reserve(3);
    
    valueUnit.emplace_back("Footman", 100);
    valueUnit.emplace_back("Archer", 95);
    valueUnit.emplace_back("Knight", 150);
    
    for(auto& list: valueUnit) {
        printUnit(&list);
    }
    
    healUnit(valueUnit[1], 20);
    
    std::cout << "\nAfter Healing:\n";
    for(auto& unit: valueUnit) {
        printUnit(&unit);
    }
    
    return 0;
}
