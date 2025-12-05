#include <iostream>
#include <memory>
#include <vector>
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

void printAverage(const std::vector<std::unique_ptr<double>>& elements) {
    if (elements.empty()) {
        std::cout << "No elements to average.\n";
        return;
    }

    double sum = 0.0;
    for (const auto& x : elements) {
        sum += *x;
    }

    double average = sum / elements.size();
    std::cout << "Average of elements: " << average << '\n';
}

int main() {
    int numElements = getInput<int>("Enter the number of elements: ");
    if (numElements <= 0) {
        std::cerr << "Number of elements must be positive.\n";
        return 1;
    }

    std::vector<std::unique_ptr<double>> elements;
    elements.reserve(numElements);
    for (int i = 0; i < numElements; ++i) {
        double value = getInput<double>("Enter value for element " + std::to_string(i + 1) + ": ");
        elements.push_back(std::make_unique<double>(value));
    }

    printAverage(elements);
    return 0;
}
