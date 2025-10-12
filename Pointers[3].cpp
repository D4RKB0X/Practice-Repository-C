#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <limits>
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
            std::cerr << "Invalid input, try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

void findMin(const std::vector<std::unique_ptr<int>>& elements) {
    auto minHere = std::min_element(elements.begin(), elements.end(), [](const auto& a, const auto& b) {
        return *a < *b;
    });
    
    if(minHere != elements.end()) {
        std::cout << "Minimum value is: " << **minHere << '\n';
    }
    else {
        std::cerr << "Vector is empty!\n";
    }
}

void findMax(const std::vector<std::unique_ptr<int>>& elements) {
    auto maxHere = std::max_element(elements.begin(), elements.end(), [](const auto& a, const auto& b) {
        return *a < *b;
    });
    
    if(maxHere != elements.end()) {
        std::cout << "Maximum value is: " << **maxHere << '\n';
    }
    else {
        std::cerr << "Vector is empty!\n";
    }
}

int main() {
    int elementsNumber = getInput<int>("Enter the number of elements: ");
    if(elementsNumber <= 0) {
        std::cerr << "Invalid Input!\n";
        return 1;
    }
    
    std::vector<std::unique_ptr<int>> elements;
    elements.reserve(elementsNumber);
    for(int i = 0; i < elementsNumber; i++) {
        int value = getInput<int>("Enter the value for element " + std::to_string(i + 1) + ": ");
        elements.emplace_back(std::make_unique<int>(value));
    }
    
    findMin(elements);
    findMax(elements);
    
    return 0;
}
