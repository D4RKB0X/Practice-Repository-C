#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

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

enum class ItemRarity {
    Common = 1, Uncommon, Rare, Epic, Legendary
};

ItemRarity intToRarity(unsigned int r) {
    switch (r) {
        case 1: return { ItemRarity::Common };
        case 2: return { ItemRarity::Uncommon };
        case 3: return { ItemRarity::Rare };
        case 4: return { ItemRarity::Epic };
        case 5: return { ItemRarity::Legendary };
        default: return { ItemRarity::Common };
    }
}

std::string rarityToString(ItemRarity r) {
    switch (r) {
        case ItemRarity::Common: { return "Common"; };
        case ItemRarity::Uncommon: { return "Uncommon"; };
        case ItemRarity::Rare: { return "Rare"; };
        case ItemRarity::Epic: { return "Epic"; };
        case ItemRarity::Legendary: {return "Legendary"; };
    }
    return "Unknown";
}

std::string getNonEmptyLine(const std::string& prompt) {
    std::string s;
    do {
        std::cout << prompt;
        std::getline(std::cin, s);
    } while (s.empty());
    return s;
}

class Item{
    private:
        std::string name;
        unsigned int gold;
        std::string info;
        ItemRarity rarity;
        
    public:
        Item(const std::string& n, unsigned int g, const std::string& i, ItemRarity r): name(n), gold(g), info(i), rarity(r) {}
        
        std::string getItemName() const { return name; }
        unsigned int getItemGold() const { return gold; }
        std::string getItemInfo() const { return info; }
        ItemRarity getItemRarity() const { return rarity; }
        
        void displayItemInfo() const {
            std::cout << name << " | "
                      << gold << " gold | "
                      << rarityToString(rarity) << " | "
                      << info << "\n";
        }
};

class SaleSystem{
    private:
        std::vector<Item> itemSale;
        
    public:
        SaleSystem(size_t rS) { itemSale.reserve(rS); }
        
        void addItemToShop(const std::string& n, unsigned int g, const std::string& i, ItemRarity r) {
            itemSale.emplace_back(n, g, i, r);
        }
        
        std::vector<Item>& getItems() { return itemSale; }
        
        void inputItems(size_t count) {
            std::string name, info;
            unsigned int gold;
            unsigned int rarityChoice;
            
            for(size_t a = 0; a < count; a++) {
                name = getNonEmptyLine("\nEnter #" + std::to_string(a+1) + " Item Name: ");
                gold = getInput<unsigned int>("Enter " + name + " Gold Cost: ");
                info = getNonEmptyLine("Enter " + name + " Description: ");
                rarityChoice = getInput<unsigned int>("Enter Rarity (1-Common | 2-Uncommon | 3-Rare | 4-Epic | 5-Legendary): ");
                ItemRarity rare = intToRarity(rarityChoice);
                
                addItemToShop(name, gold, info, rare);
            }
        }
        
        void removeItems() {
            std::string deleteItem = getNonEmptyLine("\nEnter Item Name to be Removed: ");
            
            auto value = std::remove_if(itemSale.begin(), itemSale.end(), [&](const Item& find) { return find.getItemName() == deleteItem; });
            if(value == itemSale.end()) {
                std::cerr << "Item not Found!\n";
            }
            else {
                itemSale.erase(value, itemSale.end());
                std::cout << "Item Removed!\n";
            }
        }
        
        void displayItemOnSale() const {
            std::cout << "\nItems for Sale in the Marketplace:\n";
            for (const auto& list : itemSale) {
                list.displayItemInfo();
            }
        }
};

class ItemSorter {
    public:
        static void byGold(std::vector<Item>& items) {
            std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.getItemGold() < b.getItemGold(); });
        }
    
        static void byName(std::vector<Item>& items) {
            std::sort(items.begin(), items.end(),
                      [](const Item& a, const Item& b) { return a.getItemName() < b.getItemName(); });
        }
    
        static void byRarity(std::vector<Item>& items) {
            std::sort(items.begin(), items.end(),
                      [](const Item& a, const Item& b) {
                          return static_cast<int>(a.getItemRarity()) < static_cast<int>(b.getItemRarity());
                      });
        }
};


int main() {
    
    int count = 0;
    SaleSystem magicVault(10);
    
    std::cout << "You can Enter up to 10 Items for the Marketplace:\n";
    do {
        count = getInput<int>("Enter how many Items, you'll add: ");
    }
    while (count < 1 || count > 10);
    
    magicVault.inputItems(count);
    magicVault.displayItemOnSale();
    magicVault.removeItems();

    ItemSorter::byGold(magicVault.getItems());
    magicVault.displayItemOnSale();
    
    ItemSorter::byName(magicVault.getItems());
    magicVault.displayItemOnSale();
    
    ItemSorter::byRarity(magicVault.getItems());
    magicVault.displayItemOnSale();

    return 0;
}
