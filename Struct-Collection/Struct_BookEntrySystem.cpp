#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>

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
        else {
            input.clear();
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
            
        std::cerr << "\nInvalid input! Please enter letters only (no numbers or symbols).\n\n";
    }
}

int getInt(const std::string& prompt, int min = 0, int max = 9999) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cerr << "\nInvalid input! Please enter a valid year between " << min << " and " << max << ".\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double getDouble(const std::string& prompt, double min = 0.0) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cerr << "\nInvalid input! Please enter a valid positive number.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


struct BookDetails {
    std::string title;
    std::string author;
    int year = 0;
    double price = 0.0;

    void print() const {
        std::cout << "\nBook Details\n"
                  << "-----------------------\n"
                  << "Title : " << title << '\n'
                  << "Author: " << author << '\n'
                  << "Year  : " << year << '\n'
                  << std::fixed << std::setprecision(2)
                  << "Price : $" << price << "\n-----------------------\n";
    }
};

int main() {
    std::cout << "=== Book Entry System ===\n\n";

    BookDetails book;

    book.title = getString("Enter Book Title: ");
    book.author = getString("Enter Author: ");
    book.year = getInt("Enter Year Published: ", 1000, 2025);
    book.price = getDouble("Enter Price ($): ", 0.01);

    book.print();

    std::cout << "\nData entry complete. Thank you!\n";

    return 0;
}
