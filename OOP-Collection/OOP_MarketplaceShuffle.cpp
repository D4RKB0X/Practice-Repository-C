#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void shuffleVector(std::vector<T>& v) {
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
}

class Item {
    private:
        std::string name;
        unsigned int cost;
        
    public:
        Item(const std::string& n, const unsigned int c): name(n), cost(c) {}
        
        std::string getItemName() const { return name; }
        unsigned int getItemCost() const { return cost; }
};

class Marketplace {
    private:
        std::vector<Item> vItems;
        
    public:
        Marketplace(size_t rS) { vItems.reserve(rS); }
        
        void addItem(const Item& aI) {
            vItems.emplace_back(aI);
        }
        
        void itemShuffle() {
            shuffleVector(vItems);
        }
        
        void showItems() const {
            for (const auto& item : vItems)
                std::cout << item.getItemName() << " (" << item.getItemCost() << ")\n";
        }

};

int main() {
    
    Marketplace m(5);

    m.addItem(Item("Sword", 100));
    m.addItem(Item("Shield", 150));
    m.addItem(Item("Potion", 50));
    m.addItem(Item("Gem", 75));
    m.addItem(Item("Arrow", 25));

    m.itemShuffle();
    m.showItems();
    
    return 0;
}
