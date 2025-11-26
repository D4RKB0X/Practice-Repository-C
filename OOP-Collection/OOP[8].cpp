#include <iostream>
#include <string>
#include <vector>

class Item {
    private:
        std::string name;
        unsigned int cost;
        std::string info;
    
    public:
        Item(std::string n, unsigned int c, std::string i): name(std::move(n)), cost(c), info(std::move(i)) {}
    
        const std::string& getItemName() const { return name; }
        unsigned int getItemCost() const { return cost; }
        const std::string& getItemInfo() const { return info; }
    
        void displayItemInfo() const {
            std::cout << name
                      << " | Gold Cost: " << cost
                      << " | " << info << '\n';
        }
};

class GoblinMerchant {
    private:
        std::vector<Item> vItems;
    
    public:
        explicit GoblinMerchant(size_t reserveSize) {
            vItems.reserve(reserveSize);
        }
    
        void addItem(const Item& item) {
            vItems.emplace_back(std::move(item));
        }
    
        void addItems(std::initializer_list<Item> items) {
            for (const auto& it : items) {
                vItems.emplace_back(it);
            }
        }
    
        void displayItemOnSale() const {
            std::cout << "Items for Sale on the Goblin Merchant:\n";
            for (const auto& item : vItems) {
                item.displayItemInfo();
            }
        }
};

int main() {

    GoblinMerchant forSale(11);

    forSale.addItems({
        {"Boots of Speed", 250, "Increases movement speed."},
        {"Circlet of Nobility", 200, "Increases stats by 3."},
        {"Dust of Appearance", 75, "Reveals invisible units."},
        {"Periapt of Vitality", 100, "Adds health bonus to the bearer."},
        {"Potion of Invisibility", 100, "Makes the bearer invisible when used."},
        {"Potion of Lesser Invulnerability", 150, "Grants brief invulnerability."},
        {"Scroll of Healing", 250, "Heals units in an area."},
        {"Scroll of Protection", 150, "Gives armor to units in an area."},
        {"Scroll of Town Portal", 325, "Teleports bearer and nearby units to town hall."},
        {"Staff of Teleportation", 150, "Teleports the bearer anywhere on map."},
        {"Tome of Retraining", 200, "Resets all skills to be relearned."}
    });

    forSale.displayItemOnSale();

    return 0;
}
