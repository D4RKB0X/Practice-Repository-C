#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

class Hero {
    private:
        std::string name;
        std::string classtype;
        unsigned int strength, agility, intelligence;
    
    public:
        Hero(const std::string& n, const std::string& ct, unsigned int s, unsigned int a, unsigned int i)
            : name(n), classtype(ct), strength(s), agility(a), intelligence(i) {}
    
        std::string getHeroName() const { return name; }
        std::string getHeroClass() const { return classtype; }
        unsigned int getHeroStrength() const { return strength; }
        unsigned int getHeroAgility() const { return agility; }
        unsigned int getHeroIntelligence() const { return intelligence; }
    
        double getPowerLevel() const {
            return (strength * 1.7) + (agility * 2.0) + (intelligence * 2.2);
        }
    
        void printHeroInfo() const {
            std::cout << "----------------------------------------\n";
            std::cout << "Name: " << name << "\n";
            std::cout << "Class: " << classtype << "\n";
            std::cout << "STR: " << strength
                      << " | AGI: " << agility
                      << " | INT: " << intelligence << "\n";
            std::cout << "Power Level: " << getPowerLevel() << "\n";
            std::cout << "----------------------------------------\n";
        }
};

class BuildingMenu {
    private:
        std::vector<Hero> vHeroes;
    
    public:
        BuildingMenu(size_t vSize) { vHeroes.reserve(vSize); }
    
        void startMenu() {
            unsigned int mainChoice;
    
            do {
                std::cout << "[1] Add New Hero\n"
                          << "[2] View Hero Roster\n"
                          << "[3] Search Hero\n"
                          << "[4] Exit\n"
                          << "Enter Command: ";
                std::cin >> mainChoice;
    
                switch (mainChoice) {
                    case 1: {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
                        std::string heroName, heroClass;
                        unsigned int str, agi, inte;
    
                        std::cout << "--- Add New Hero ---\n";
    
                        std::cout << "Enter Hero Name: ";
                        std::getline(std::cin, heroName);
    
                        std::cout << "Enter Hero Class: ";
                        std::getline(std::cin, heroClass);
    
                        std::cout << "Enter Hero Strength: ";
                        std::cin >> str;
    
                        std::cout << "Enter Hero Agility: ";
                        std::cin >> agi;
    
                        std::cout << "Enter Hero Intelligence: ";
                        std::cin >> inte;
    
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
                        vHeroes.emplace_back(heroName, heroClass, str, agi, inte);
    
                        std::cout << ">>> Hero " << heroName << " has joined your forces!\n";
                        std::cout << ">>> Calculating Power Level... Done!\n";
    
                        break;
                    }

                    case 2: {
                        if (vHeroes.empty()) {
                            std::cout << "No heroes recruited yet.\n";
                            break;
                        }
    
                        std::cout << "--- Hero Roster ---\n";
                        for (const auto& h : vHeroes) {
                            h.printHeroInfo();
                        }
                        break;
                    }
    
                    case 3: {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
                        std::string findHero;
                        std::cout << "Enter Hero Name to Find: ";
                        std::getline(std::cin, findHero);
    
                        auto it = std::find_if(vHeroes.begin(), vHeroes.end(), [&](const Hero& h) { return h.getHeroName() == findHero; });
    
                        if (it != vHeroes.end()) {
                            std::cout << ">>> Hero Found!\n";
                            it->printHeroInfo();
                        }
                        
                        else {
                            std::cout << "Hero \"" << findHero << "\" not found.\n";
                        }
                        
                        break;
                    }
    
                    case 4: {
                        std::cout << "Exiting the System... Goodbye!\n";
                        break;
                    }

                    default: {
                        std::cerr << "Invalid Option!\n";
                        break;
                    }
                        
                }
            } while (mainChoice != 4);
        }
};

int main() {
    BuildingMenu AltarofHeroes(4);
    AltarofHeroes.startMenu();
    return 0;
}
