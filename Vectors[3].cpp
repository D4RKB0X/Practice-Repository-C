#include <iostream>
#include <algorithm>
#include <vector>
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

std::vector<int> getNumbers(int count) {
    std::vector<int> nums;
    for (int i = 0; i < count; i++) {
        int value = getInput<int>("Enter a number: ");
        nums.push_back(value);
    }
    return nums; 
}

int largestNumber(const std::vector<int>& numbers) {
    return *std::max_element(numbers.begin(), numbers.end());
}

int main() {
    std::vector<int> numbers = getNumbers(5);
    int maxValue = largestNumber(numbers);

    std::cout << "Largest number is: " << maxValue << '\n';
    return 0;
}
