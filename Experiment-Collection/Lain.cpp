#include <iostream>
#include <string>
#include <memory>

class Unit {
    protected:
        std::string name;
        unsigned int health;
        unsigned int damage;
        
    public:
        Unit(const std::string& n,
             unsigned int h,
             unsigned int d)
            :name(n), health(h), damage(d) {
                if(h == 0 || d == 0) {
                   throw std::invalid_argument("Health or Damage must be greater than 0!\n");
                }
            }
        
        const std::string& getUnitName() const { return name; }
        unsigned int getUnitHealth() const { return health; }
        unsigned int getUnitDamage() const { return damage; }
        
        virtual void attackAnimation() const = 0;
        virtual void unitAbilities() const = 0;
        
        void printInfo() const {
            std::cout << "Name: " << name
                      << " | Health: " << health
                      << " | Damage: " << damage << '\n';
        }
        
        virtual ~Unit() = default;
};

class Footman final : public Unit {
    private:
        unsigned int defense;
        
    public:
        Footman(const std::string& n = "Footman",
                unsigned int h = 150, 
                unsigned int d = 10, 
                unsigned int def = 5)
                : Unit(n, h, d), defense(def) {
                    std::cout << "Ready for action!\n";
                }
            
        void attackAnimation() const override {
            std::cout << "Attack Animation: " << name << " swings their sword!\n";
        }
        
        void unitAbilities() const override {
            std::cout << "Ability: " << name << " uses Shield to gain " << defense << " armor from Defense!\n";
        }
};

class Archer final : public Unit {
    private:
        unsigned int grace;
        
    public:
        Archer(const std::string& n = "Archer",
               unsigned int h = 125,
               unsigned int d = 15,
               unsigned int g = 10)
               : Unit(n, h, d), grace(g) {
                   std::cout << "I stand ready!\n";
               }
               
        void attackAnimation() const override {
            std::cout << "Attack Animation: " << name << " shoots an arrow!\n";
        }
        
        void unitAbilities() const override {
            std::cout << "Ability: " << name << " deals extra " << grace << " damage from Elune's Grace!\n";
        }
};

int main() {
    
    std::cout << "Hello Elven Barracks!\n";
    std::cout << "--------------------\n";
    
    std::unique_ptr<Unit> ftmn = std::make_unique<Footman>();
    ftmn->printInfo();
    ftmn->attackAnimation();
    ftmn->unitAbilities();
    
    std::cout << "--------------------\n";
    
    std::unique_ptr<Unit> arch = std::make_unique<Archer>();
    arch->printInfo();
    arch->attackAnimation();
    arch->unitAbilities();
    
    std::cout << "--------------------\n";
    std::cout << "Goodbye!\n";
    
    return 0;
}
