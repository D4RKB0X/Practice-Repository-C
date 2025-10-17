#include <iostream>
#include <string>
#include <cctype> 
#include <limits>

std::string getInputCardNumber(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
        value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);

        if (value.empty()) {
            std::cerr << "Input cannot be empty. Try again.\n";
            continue;
        }

        std::string cleaned;
        for (char c : value) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                cleaned.push_back(c);
            }
        }

        if (cleaned.empty()) {
            std::cerr << "Input must contain digits only. Try again.\n";
            continue;
        }
        else if (cleaned.length() < 13 || cleaned.length() > 19) {
            std::cerr << "Card number must be 13–19 digits long. Try again.\n";
            continue;
        }

        bool allSame = true;
        for (size_t i = 1; i < cleaned.size(); ++i) {
            if (cleaned[i] != cleaned[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            std::cerr << "Card number cannot have all digits identical. Try again.\n";
            continue;
        }
        else {
            return cleaned;
        }
    }
}

bool luhnAlgorithm(const std::string& number) {
    int sum = 0;
    bool doubleDigit = false;

    for (size_t i = number.size(); i-- > 0;) {
        int digit = number[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10) == 0;
}

int main() {
    std::string card = getInputCardNumber("Enter card number: ");

    if (luhnAlgorithm(card)) {
        std::cout << "Valid!\n";
    } else {
        std::cout << "Invalid!\n";
    }

    return 0;
}
