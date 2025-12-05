#include <iostream>
#include <string>
#include <vector>

class Unit {
    private:
        std::string name;
        unsigned int attack;
    
    public:
        Unit(std::string n, unsigned int a): name(n), attack(a) {};
        unsigned int train() { return attack += 5; }
        
        void printStats() const {
            std::cout << name << " - Attack: " << attack << '\n';
        }
};

class Upgrades {
    private:
        std::vector<Unit> vUnits;
    
    public:
        Upgrades(size_t reserveSize) { 
            vUnits.reserve(reserveSize);
        }
    
        void addUnit(Unit& u) {
            vUnits.emplace_back(u);
        };
        
        void trainAll() {
            for(auto& upg : vUnits) {
                upg.train();
            }
        };
        
        void showAllUnits() const {
            for(const auto& all : vUnits) {
                all.printStats();
            }
        };
};

int main() {
    
    Unit footman("Footman", 10);
    Unit archer("Archer", 13);
    Unit knight("Knight", 20);
    
    Upgrades blacksmith(3);
    blacksmith.addUnit(footman);
    blacksmith.addUnit(archer);
    blacksmith.addUnit(knight);
    
    std::cout << "Before Training:\n";
    blacksmith.showAllUnits();
    
    std::cout << "\nTraining all units...\n";
    blacksmith.trainAll();
    
    std::cout << "\nAfter Training:\n";
    blacksmith.showAllUnits();
    
    return 0;
}
