#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <utility>

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

std::pair<int,int> countEvenAndOdd(const std::vector<int>& elements) {
    
    int evenCount = 0;
    int oddCount = 0;
    
    for(auto x: elements) {
        if(x % 2 == 0) {
            evenCount++;
        }
        else {
            oddCount++;
        }
    }
    
    return std::make_pair(evenCount, oddCount);
}

int main() {
    
    std::vector<int> elements;
    
    int value = getInput<int>("Enter the size of the vector: ");
    for(size_t i = 0; i < value; i++) {
        int num = getInput<int>("Enter element " + std::to_string(i+1) + ": ");
        elements.push_back(num);
    }
    
    std::pair<int,int> result = countEvenAndOdd(elements);
    
    std::cout << "Even numbers are: " << result.first << "\n";
    std::cout << "Odd numbers are: " << result.second << "\n";
    
    return 0;
}
