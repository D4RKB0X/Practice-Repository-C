#include <iostream>
#include <string>

struct Unit {
    std::string name;
    int health = 0;
    int attack = 0;
    
    Unit() = default;
    Unit(std::string n, int h, int a) : name(n), health(h), attack(a) {}
};

void attackUnit(Unit& attacker, Unit& defender) {
    std::cout << attacker.name << " attacks " << defender.name
              << " for " << attacker.attack << " damage!\n";
              
    defender.health -= attacker.attack;
    if (defender.health < 0) defender.health = 0;

    std::cout << defender.name << "'s health: " << defender.health << "\n\n";
}

int main() {
    Unit footman("Footman", 100, 15);
    Unit archer("Archer", 90, 10);

    std::cout << "=== Battle Start ===\n\n";

    while (footman.health > 0 && archer.health > 0) {
        attackUnit(footman, archer);
        if (archer.health <= 0) break;

        attackUnit(archer, footman);
    }

    if (footman.health > 0) std::cout << footman.name << " wins the battle!\n";
    else std::cout << archer.name << " wins the battle!\n";

    return 0;
}
