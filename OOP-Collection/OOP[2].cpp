#include <iostream>
#include <string>
#include <vector>

class Weapon {
    private:
        std::string Wname;
        unsigned int Wdamage;
    
    public:
        Weapon(std::string n, unsigned int d) : Wname(n), Wdamage(d) {}
    
        unsigned int getWDamage() const { return Wdamage; }
        std::string getWName() const { return Wname; }
    
        void printWeapon() const {
            std::cout << Wname << " has " << Wdamage << " DPS!\n";
        }
};

class Unit {
    private:
        std::string Uname;
        unsigned int Uhealth;
        Weapon* equippedWeapon = nullptr;

    public:
        Unit(std::string n, unsigned int h) : Uname(n), Uhealth(h) {}
    
        void equipWeapon(Weapon& w) {
            equippedWeapon = &w;
        }
    
        void attack(Unit& target) {
            if (equippedWeapon) {
                unsigned int dmg = equippedWeapon->getWDamage();
                target.takeDamage(dmg);
                std::cout << Uname << " attacks " << target.getUName()
                          << " with " << equippedWeapon->getWName()
                          << " for " << dmg << " damage!\n";
            } else {
                std::cout << Uname << " has no weapon to attack with!\n";
            }
        }
    
        void takeDamage(unsigned int dmg) {
            if (dmg >= Uhealth) Uhealth = 0;
            else Uhealth -= dmg;
        }
    
        void printUnit() const {
            std::cout << Uname << " has " << Uhealth << " HP!\n";
        }
    
        std::string getUName() const { return Uname; }
        unsigned int getUHealth() const { return Uhealth; }
};

int main() {
    Unit footman("Footman", 100);
    Unit archer("Archer", 90);

    Weapon sword("Sword", 15);
    Weapon bow("Bow", 10);

    footman.equipWeapon(sword);
    archer.equipWeapon(bow);

    std::cout << "=== Initial Status ===\n";
    footman.printUnit();
    archer.printUnit();
    std::cout << "\n";

    footman.attack(archer);

    std::cout << "\n=== Updated Status ===\n";
    footman.printUnit();
    archer.printUnit();

    return 0;
}
