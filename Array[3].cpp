#include <iostream>
#include <algorithm>
#include <array>

int findElement(std::array<int, 5>& arr, int &element) {
    
    int found = 0;
    auto get = std::find(arr.begin(), arr.end(), element);
    
    if(get != arr.end()) {
        int index = std::distance(arr.begin(), get);
        std::cout << "The element " << element << " is found at index " << index;
        return index;
    }
    else {
        std::cout << "Element not found!\n";
        return -1;
    }
}

int main() {
    
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    int element = 0;
    
    std::cout << "Enter the element you want to find: ";
    std::cin >> element;
    
    int found = findElement(arr, element);
    
    std::cout << "\nGoodbye!";
    
    return 0;
}
