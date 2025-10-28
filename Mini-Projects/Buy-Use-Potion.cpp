#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while(true) {
        std::cout << prompt;
        std::cin >> value;
        
        if(std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cout << "Invalid Input! Try Again!\n";
           continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

bool getYesNo(const std::string& prompt) {
    char choice;
    while(true) {
        std::cout << prompt << " (y/n): ";
        std::cin >> choice;
        choice = std::tolower(choice);

        if(choice == 'y') return true;
        if(choice == 'n') return false;

        std::cout << "Invalid choice! Enter y or n.\n";
    }
}

void buyPotion(int &gold, int &inventory) {
    if(gold >= 25) {
        gold -= 25;
        inventory++;
        std::cout << "You've bought a Potion of Health!\n";
    } else {
        std::cout << "Not enough gold!\n";
    }
}

void usePotion(int &HP, int &inventory, int maxHP) {
    int healAmount = 100;
    
    if(inventory > 0) {
        HP = std::min(HP + healAmount, maxHP);
        inventory--;
        std::cout << "You healed " << healAmount 
                  << ". Your current health is " << HP << ".\n";
    } else {
        std::cout << "No potions left!\n";
    }
}

int main() {
    int gold = 100, HP = 250, maxHP = 500, inventory = 0;

    std::cout << "You have " << gold << " gold, HP = " << HP 
              << "/" << maxHP << ", and " << inventory << " potions.\n";

    if(getYesNo("Do you want to buy a potion for 25 gold?")) {
        buyPotion(gold, inventory);
    }

    if(getYesNo("Do you want to use a potion?")) {
        usePotion(HP, inventory, maxHP);
    }

    std::cout << "\nFinal status:\n";
    std::cout << "Gold: " << gold 
              << "\nHP: " << HP 
              << "\nPotions: " << inventory << "\n";

    return 0;
}
