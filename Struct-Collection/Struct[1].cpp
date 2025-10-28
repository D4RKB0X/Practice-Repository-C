#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

std::string getString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t end = input.find_last_not_of(' ');
        if (start != std::string::npos) {
            input = input.substr(start, end - start + 1);
        }

        bool valid = !input.empty();
        for (char c : input) {
            if (!std::isalpha(c) && !std::isspace(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            return input;
        }
        else {
            std::cerr << "Invalid input! Please enter letters only (no numbers or symbols).\n\n";
        }
    }
}


int getIntInRange(const std::string& prompt, int min, int max) {
    int number;
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number >= min && number <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return number;
        }
        std::cerr << "Please enter a number between " << min << " and " << max << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

struct SpellBook {
    std::string name;
    std::vector<std::string> spells;

    void addSpell(const std::string& spell) {
        spells.push_back(spell);
    }

    void print() const {
        std::cout << "\nSpellbook: " << name << '\n';
        std::cout << "Spells: " << '\n';
        for (const auto& spell : spells)
            std::cout << " - " << spell << '\n';
    }
};

int main() {
    SpellBook book;

    book.name = getString("Enter the name of your spellbook: ");
    int numSpells = getIntInRange("How many spells do you want to add (3–5)? ", 3, 5);

    for (int i = 0; i < numSpells; ++i) {
        std::string spell = getString("Enter spell " + std::to_string(i + 1) + ": ");
        book.addSpell(spell);
    }

    book.print();

    return 0;
}
