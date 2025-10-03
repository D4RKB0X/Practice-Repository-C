#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input, try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}


void printAlphabet(std::vector<char>& alphabet) {
    for(auto c: alphabet) {
        std::cout << c << ' ';
    }
    std::cout << '\n';
}

void getLetterAtIndex(std::vector<char>& alphabet) {
    
    int index = getInput<int>("Enter an index (0-25): ");
    if (index >= 0 && index < alphabet.size()) {
        std::cout << "\nLetter at index " << index << " is: " << alphabet[index] << '\n';
    }
    else {
        std::cout << "Invalid Index!\n";
        return;
    }
}

void reverseAlphabet (std::vector<char>& alphabet) {
    std::reverse(alphabet.begin(), alphabet.end());
    
    std::cout << "Reverse sort: ";
    for(auto x : alphabet) {
        std::cout << x << ' ';
    }
}

int main() {
    
    std::vector<char> alphabet(26);
    std::iota(alphabet.begin(), alphabet.end(), 'A');
    
    printAlphabet(alphabet);
    getLetterAtIndex(alphabet);
    reverseAlphabet(alphabet);
    
    return 0;
}
