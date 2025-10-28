#include <iostream>
#include <vector>
#include <algorithm>

void sortPlease(std::vector<int>& arr) {
    
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    
    std::cout << "Reverse sort: ";
    for(auto x: arr) {
        std::cout << x << ' ';
    }
}

int main() {
    int x;
    
    std::cout << "Enter the size of the vector: ";
    std::cin >> x;
    
    if(x <= 0) {
        std::cout << "Size number must be positive!\n";
        return 1;
    }
    
    std::cout << "Enter elements of the vector: ";
    std::vector<int> arr(x);
    
    for(int i = 0; i < x; i++) {
        std::cin >> arr[i];
    }
    
    sortPlease(arr);
}
