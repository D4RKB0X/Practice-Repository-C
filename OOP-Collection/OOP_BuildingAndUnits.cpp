#include <iostream>
#include <string>
#include <vector>

class Unit {
    private:
        std::string name;
        unsigned int health;
        unsigned int damage;
        
    public:
        Unit(const std::string& n, unsigned int h, unsigned d): name(n), health(h), damage(d) {}
        
        const std::string& getUnitName() const { return name; }
        const unsigned int getUnitHealth() const { return health; }
        const unsigned int getUnitDamage() const { return damage; }
        
        void printUnitInfo() const {
            std::cout << "Name: " << name << " | Health: " << health << " | Damage: " << damage << '\n';
        }
};

class Building {
    private:
        std::string name;
        std::vector<Unit> vUnits;
        
    public:
        Building(const std::string& n, size_t rS): name(n) { vUnits.reserve(rS); }
        
        const std::string& getBuildingName() const { return name; }
        
        void addUnit(const Unit& aU) {
            vUnits.emplace_back(std::move(aU));
        }
        
        void showUnits() const {
            for(const auto& list: vUnits) {
                list.printUnitInfo();
            }
        }
};

int main() {
    
    Building brcks("Barracks", 1);
    Unit ftmn("Footman", 100, 10);
    Unit achr("Archer", 75, 15);
    
    brcks.addUnit(ftmn);
    brcks.addUnit(achr);
    
    std::cout << "Available Units:\n";
    brcks.showUnits();
    
    return 0;
}
