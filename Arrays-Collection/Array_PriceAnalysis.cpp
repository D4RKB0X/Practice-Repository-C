#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while(true) {
        std::cout << prompt;
        std::cin >> value;
        
        if(std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cout << "Invalid Input! Try Again!\n";
           continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

double getTotal(double prices[], int size) {
    double total = 0;
    for(std::size_t i = 0; i < size; i++) {
        total += prices[i];
    }
    
    return total;
}

double getAverage(double prices[], int size) {
    double average = 0;
    average = getTotal(prices, size) / size;
    
    return average;
}

double getMax(double prices[], int size) {
    double max = *std::max_element(prices, prices + size);
    return max;
}

double getMin(double prices[], int size) {
    double min = *std::min_element(prices, prices + size);
    return min;
}

int getCount(double prices[], int size) {
    int count = 0;
    double avg = getAverage(prices, size);
    
    for(std::size_t i = 0; i < size; i++) {
        if(prices[i] > avg) {
            count++;
        }
    }
    
    return count;
}

int main() {
    
    double prices[5];
    
    for(std::size_t i = 0; i < 5; i++) {
        prices[i] = getInput<double>("Enter 5 numbers: ");
    }
    
    std::cout << '\n';
    int size = std::size(prices);
    
    double total = getTotal(prices, size);
    double average = getAverage(prices, size);
    double max = getMax(prices, size);
    double min = getMin(prices, size);
    int count = getCount(prices, size);
    
    std::cout << total << "$ total price.\n";
    std::cout << average << "$ average.\n";
    std::cout << max << "$ max price.\n";
    std::cout << min << "$ min price.\n";
    std::cout << count << " count of prices above average.\n";
    
    return 0;
}
