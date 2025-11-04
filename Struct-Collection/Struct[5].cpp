#include <iostream>
#include <string>
#include <vector>

struct Grocery {
    std::string name;
    int quantity = 0;
    double price = 0.0;

    Grocery() = default;
    Grocery(std::string n, int q, double p) : name(n), quantity(q), price(p) {}
};

void showBasket(const std::vector<Grocery>& items) {
    if (items.empty()) {
        std::cerr << "No items in basket.\n";
        return;
    }

    for (const auto& list : items) {
        std::cout << "Name: " << list.name
                  << " | Quantity: " << list.quantity
                  << " | Price: " << list.price << '\n';
    }
}

double totalCost(const std::vector<Grocery>& items) {
    double sum = 0.0;
    for (const auto& cost : items) {
        sum += cost.quantity * cost.price;
    }
    return sum;
}

int main() {
    std::vector<Grocery> items;
    items.reserve(3);

    items.emplace_back("Milk", 2, 50);
    items.emplace_back("Bread", 1, 35);
    items.emplace_back("Eggs", 12, 6);

    showBasket(items);
    std::cout << "\nTotal cost: " << totalCost(items);
}
