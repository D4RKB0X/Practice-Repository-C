#include <iostream>
#include <limits>
#include <iterator>
#include <string>

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

double average(const int arr[], std::size_t size) {
    
    double sum = 0;
    
    for(std::size_t i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    
    avg = sum / size;
    std::cout << avg;
    
    return avg;
}

int main() {
    
    int arr[5];
    
    for(std::size_t i = 0; i < 5; i++) {
        arr[i] = getInput<int>("Enter 5 numbers: ");
    }
    
    average(arr, std::size(arr));
    
    return 0;
}
