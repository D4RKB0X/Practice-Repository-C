#include <iostream>
#include <string>
#include <memory>

class Unit {
    protected:
        std::string name;
        unsigned int health;
        
    public:
        Unit(const std::string& n, unsigned int h)
            : name(n), health(h) {}
        
        std::string getUnitName() const { return name; }
        unsigned int getUnitHealth() const { return health; }
        
        virtual void takeDamage(unsigned int dmg) {
            if (dmg >= health) {
                health = 0;
                std::cout << name << " has been killed!\n";
            } else {
                health -= dmg;
                std::cout << name << " has taken " << dmg << " damage!\n";
            }
        }
    
        virtual void printUnitInfo() const {
            std::cout << "Name: " << name << " | Health: " << health << '\n';
        }
    
        virtual ~Unit() = default;
};

class UnitUpgrade : public Unit {
    public:
        UnitUpgrade(const std::string& n, unsigned int h = 150)
            : Unit(n, h) {}
};

class EliteUpgrade : public UnitUpgrade {
    public:
        EliteUpgrade(const std::string& n)
            : UnitUpgrade(n) {}
    
        void rallyUnits() const {
            std::cout << getUnitName() << " rallies the troops!\n";
        }
};

class Building {
    public:
        std::unique_ptr<EliteUpgrade> promote(std::unique_ptr<UnitUpgrade> newUnit, const std::string& newName) {
            std::cout << "Promotion Complete!\n\n";
            return std::make_unique<EliteUpgrade>(newName);
        }
};

int main() {
    // Step 1: Footman (starting unit)
    Unit ftmn("Footman", 100);
    ftmn.printUnitInfo();
    ftmn.takeDamage(25);
    ftmn.printUnitInfo();

    std::cout << "\n";

    // Step 2: Upgrade Footman to Swordsman
    std::unique_ptr<UnitUpgrade> swrdmn = std::make_unique<UnitUpgrade>("Swordsman", ftmn.getUnitHealth());
    swrdmn->printUnitInfo();
    swrdmn->takeDamage(50);
    swrdmn->printUnitInfo();

    std::cout << "\n";

    // Step 3: Upgrade Swordsman to Knight
    Building brcks;
    std::unique_ptr<EliteUpgrade> knght = brcks.promote(std::move(swrdmn), "Knight");
    knght->printUnitInfo();
    knght->rallyUnits();
    std::cout << "--------------------\n";
    knght->takeDamage(75);
    knght->printUnitInfo();

    std::cout << "\n";

    // Step 4: Upgrade Knight to Captain
    std::unique_ptr<EliteUpgrade> captain = brcks.promote(std::move(knght), "Captain");
    captain->printUnitInfo();
    captain->rallyUnits();
    std::cout << "--------------------\n";
    captain->takeDamage(100);
    captain->printUnitInfo();

    return 0;
}
