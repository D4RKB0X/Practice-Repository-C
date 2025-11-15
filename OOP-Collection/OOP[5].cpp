#include <iostream>
#include <string>
#include <random>

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    std::uniform_int_distribution<int> dist(min, max);
    
    return dist(gen);
}

class Unit {
    private:
        std::string name;
        unsigned int health;
    
    public:
        Unit(const std::string& n, unsigned int h) : name(n), health(h) {}
    
        std::string getUnitName() const { return name; }
        unsigned int getUnitHealth() const { return health; }
    
        void printUnitInfo() const {
            std::cout << "Unit name: " << name << " | Health: " << health << '\n';
        }
    
        void takeDamage(int dmg) {
            if (dmg >= static_cast<int>(health)) {
                health = 0;
                std::cout << name << " has taken " << dmg << " damage and is dead!\n";
            } else {
                health -= dmg;
                std::cout << name << " has taken " << dmg << " damage. Health is now: " << health << '\n';
            }
        }
    
        void hardenedSkin(int incomingDamage) {
            int maxReduction = 8;
            int minReduction = 3;
    
            int finalDamage = incomingDamage;
    
            if (incomingDamage < minReduction) {
                finalDamage = 0;
                std::cout << name << " takes no damage due to Hardened Skin!\n";
            } else if (incomingDamage < maxReduction) {
                finalDamage = incomingDamage - minReduction;
                std::cout << name << "'s Hardened Skin reduces damage from " 
                          << incomingDamage << " to " << finalDamage << "!\n";
            }
    
            takeDamage(finalDamage);
        }
};

class Building {
    private:
        std::string name;
        unsigned int health;
    
    public:
        Building(const std::string& n, unsigned int h) : name(n), health(h) {}
    
        std::string getBuildingName() const { return name; }
        unsigned int getBuildingHealth() const { return health; }
    
        void printBuildingInfo() const {
            std::cout << "Building name: " << name << " | Health: " << health << '\n';
        }
    
        void researchHardenedSkin(Unit& unit, int incomingDamage) const {
            unit.hardenedSkin(incomingDamage);
        }
};

int main() {
    Unit mG("Mountain Giant", 1600);
    mG.printUnitInfo();

    Building hH("Hunter's Hall", 1100);
    hH.printBuildingInfo();

    int attack1 = 100;
    std::cout << "\nNormal attack:\n";
    mG.takeDamage(attack1);

    int attack2 = getRandomNumber(0, 20);
    std::cout << "\nAnother attack after Hardened Skin:\n";
    hH.researchHardenedSkin(mG, attack2);

    return 0;
}
