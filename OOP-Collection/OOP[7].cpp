#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>

class Unit {
    private:
        std::string name;
        unsigned int health;
        unsigned int damage;
        
    public:
        Unit(const std::string& n, unsigned int h, unsigned int d): name(n), health(h), damage(d) {}
        
        std::string getUnitName() const { return name; }
        unsigned int getUnitHealth() const { return health; }
        unsigned int getUnitDamage() const { return damage; }
        
        void printInfo() const {
            std::cout << "Name: " << name
                      << " | Health: " << health
                      << " | Damage: " << damage << '\n';
        }
};

class Building {
    private:
        std::string name;
        unsigned int health;
        std::vector<std::unique_ptr<Unit>> vUnit;
        
    public:
        Building(std::string n, unsigned int h, size_t rS): name(n), health(h) { vUnit.reserve(rS); }
        
        std::string getBuildingName() const { return name; }
        unsigned int getBuildingHealth() const { return health; }
        
        void addUnit(const std::string& n, unsigned int h, unsigned int d) {
            vUnit.emplace_back(std::make_unique<Unit>(std::move(n), h, d));
        }
        
        void trainUnit() const {
            std::cout << "Units inside " << name << ":\n";
            for (const auto& unit : vUnit) {
                unit->printInfo();
            }
        }
};

int main() {
    
    Building brcks("Barracks", 1500, 3);
    
    std::string name;
    unsigned int hp, dmg;
    
    std::cout << "Enter 3 Units for the Barracks:\n";
    for(size_t i = 0; i < 3; i++) {
        std::cout << "Enter Unit #" << i+1 << " Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter Health of " << name << ": ";
        std::cin >> hp;
        
        std::cout << "Enter Damage of " << name << ": ";
        std::cin >> dmg;
        
        brcks.addUnit(name, hp, dmg);
        std::cout << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    brcks.trainUnit();
    
    return 0;
}
