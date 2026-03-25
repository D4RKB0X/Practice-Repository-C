#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Unit {
    protected:
        std::string name;
        unsigned int health;
        unsigned int damage;
        bool alive;
        
    public:
        Unit(const std::string& n, unsigned int h, unsigned int d)
            :name(n), health(h), damage(d), alive(true) {}
        
        const std::string getUnitName() const { return name; }
        unsigned int getUnitHealth() const { return health; }
        unsigned int getUnitDamage() const { return damage; }
        bool isAlive() const { return health > 0; }
        
        virtual void attackUnit(Unit& target) {
            if(!alive) {
                std::cout << name << " is dead and cannot attack!\n";
            }
            else {
                std::cout << name << " attacks " << target.getUnitName() << "!\n";
                target.takeDamage(damage);
            }
        }
        
        virtual void takeDamage(unsigned int dmg) {
            if(!alive) { return; }
                if(dmg >= health) {
                    health = 0;
                    alive = false;
                    std::cout << name << " has been killed!\n";
                }
                else {
                    health -= dmg;
                    std::cout << name << " has taken " << dmg << " damage!\n";
                }
        }
        
        void printUnitStatus() const {
            std::cout << "Name: " << name
                      << " | Health: " << health
                      << " | Damage: " << damage << '\n';
        }
        
        virtual ~Unit() = default;
};

class Footman : public Unit {
    private:
        unsigned int armor = 5;
    
    public:
        Footman(const std::string& n = "Footman", unsigned int h = 150, unsigned int d = 10)
            :Unit(n, h, d) {}
            
        void takeDamage(unsigned int dmg) override {
            if(!alive) {
                return;
            }
            else {
                unsigned int reducedDamage = (dmg > armor) ? (dmg - armor) : 1;
                std::cout << name << "'s armor is blocked " << (dmg - reducedDamage) << " damage!\n";
                
                Unit::takeDamage(reducedDamage);
            }
        }
};

class Archer : public Unit {
    public:
        Archer(const std::string& n = "Archer", unsigned int h = 100, unsigned int d = 15)
            :Unit(n, h, d) {}
            
        void attackUnit(Unit& target) override {
            if(!alive) {
                return;
            }
            else {
                unsigned int finalDamage = damage;
                
                if(rand() % 5 == 0) {
                    finalDamage *= 2;
                    std::cout << finalDamage << " Dealt!\n";
                }
                
                std::cout << name << " shoots an arrow at " << target.getUnitName() << "!\n";
                target.takeDamage(finalDamage);
            }
        }
};

int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    Footman player("Arthas");
    Archer enemy("Sylvanas"); 

    player.printUnitStatus();
    enemy.printUnitStatus();
    
    int numRounds = 1;
    std::cout << "----------\n";
    while(player.isAlive() && enemy.isAlive()) {
        std::cout << "Round " << numRounds << ":\n";
        
        player.attackUnit(enemy);
        if(enemy.isAlive()) {
            enemy.attackUnit(player);
        }
        
        std::cout << "----------\n";
        numRounds++;
    }
    
    if (player.isAlive()) {
        std::cout << "VICTORY! " << player.getUnitName() << " survived with " << player.getUnitHealth() << " HP.\n";
    }
    
    else {
        std::cout << "DEFEAT... " << enemy.getUnitName() << " wins the day.\n";
    }
    
    return 0;
}
