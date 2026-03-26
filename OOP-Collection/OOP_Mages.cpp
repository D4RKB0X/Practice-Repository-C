#include <iostream>
#include <string>
#include <memory>

class Unit {
    protected:
        std::string name;
        unsigned int health;
        unsigned int mana;
        unsigned int damage;
        
    public:
        Unit(const std::string& n, unsigned int h, unsigned int m, unsigned int d)
            :name(n), health(h), mana(m), damage(d) {}
        
        const std::string& getUnitName() const { return name; }
        unsigned int getUnitHealth() const { return health; }
        unsigned int getUnitMana() const { return mana; }
        unsigned int getUnitDamage() const { return damage; }
        
        virtual void printUnitInfo() const {
            std::cout << "Name: " << name
                      << " | Health: " << health
                      << " | Mana: " << mana
                      << " | Damage: " << damage << '\n';
        }
        
        virtual void attackAnimation() const = 0;
        virtual void spellAbilities() const = 0;
        
        virtual ~Unit() = default;
};

class Priest : public Unit {
    public:
        Priest(const std::string& n = "Priest", unsigned int h = 100, unsigned int m = 150, unsigned int d = 10)
            :Unit(n, h, m, d) {}
            
        void attackAnimation() const override {
            std::cout << name << " swings his staff to attack!\n";
        }
        
        void spellAbilities() const override {
            std::cout << "Available Spells: Heal | Dispel Magic | Inner Fire\n";
        }
};

class Sorceress : public Priest {
    public:
        Sorceress(const std::string& n = "Sorceress", unsigned int h = 125, unsigned int m = 175, unsigned int d = 15)
            :Priest(n, h, m, d) {}
            
        void attackAnimation() const override {
            std::cout << name << " swings her hands to attack!\n";
        }
        
        void spellAbilities() const override {
            std::cout << "Available Spells: Slow | Invisibility | Polymorph\n";
        }
};

int main() {
    
    std::unique_ptr<Unit> prst = std::make_unique<Priest>();
    std::unique_ptr<Unit> srcs = std::make_unique<Sorceress>();
    
    prst->printUnitInfo();
    prst->attackAnimation();
    prst->spellAbilities();
    
    std::cout << "------------------------------\n";
    
    srcs->printUnitInfo();
    srcs->attackAnimation();
    srcs->spellAbilities();
    
    return 0;
}
