#include <iostream>
#include <string>
#include <cctype>

bool allDigitsSame(const std::string& s) {
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

std::string getInputCardNumber(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
        value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);


        std::string cleaned;
        for (char c : value) if (std::isdigit(static_cast<unsigned char>(c))) cleaned.push_back(c);

        if (cleaned.empty()) {
            std::cerr << "Input must contain digits only.\n";
        }
        else if (cleaned.size() < 13 || cleaned.size() > 19) {
            std::cerr << "Card number must be 13–19 digits long.\n";
        }
        else if (allDigitsSame(cleaned)) {
            std::cerr << "Card number cannot have all identical digits.\n";
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
