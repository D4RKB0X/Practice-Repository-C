#include <iostream>
#include <memory>
#include <limits>
#include <algorithm>
#include <vector>
#include <string>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\nInvalid input, try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

void functionVector(std::vector<int>& myVector) {
    std::cout << "\nPrinted Elements: ";
    for (const auto& value : myVector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Swapped Numbers: ";
    if(!myVector.empty()) {
        std::swap(myVector.front(), myVector.back());
        for(const auto& newValue : myVector) {
            std::cout << newValue << ' ';
        }
    }
}

int main() {
    std::vector<int> myVector;
    
    for(int i = 0; i < 5; i++) {
        auto element = std::make_unique<int>(getInput<int>("Enter 5 elements: "));
        myVector.emplace_back(*element);
    }
    
    functionVector(myVector);
    
    return 0;
}
