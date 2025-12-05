#include <iostream>
#include <vector>
#include <map>
#include <string>

constexpr int BASE_FIREBALL_DAMAGE = 120;
constexpr int BASE_FROSTBOLT_DAMAGE = 80;

int preCastModifiers(int baseDamage, int casterIntelligence, int spellPowerBoost) {
    return baseDamage + casterIntelligence * 2 + spellPowerBoost;
}

int postCastEffects(int modifiedDamage, float enemyResistance, bool criticalHit) {
    int damage = static_cast<int>(modifiedDamage * (1.0f - enemyResistance));
    if(criticalHit) damage *= 2;
    return damage;
}

int main() {
    std::vector<std::string> backpack = {"Health Potion", "Mana Potion", "Sword"};

    std::map<std::string, int> spellbook;
    spellbook["Fireball"] = BASE_FIREBALL_DAMAGE;
    spellbook["Frostbolt"] = BASE_FROSTBOLT_DAMAGE;
    spellbook["Lightning"] = 150;

    std::cout << "Backpack:\n";
    for(size_t i = 0; i < backpack.size(); i++) {
        std::cout << i+1 << ". " << backpack[i] << "\n";
    }

    std::cout << "\nSpellbook:\n";
    for(auto &[spell, damage] : spellbook) {
        std::cout << spell << " -> Base Damage: " << damage << "\n";
    }

    int intelligence = 15;
    int spellPowerBoost = 10;
    float enemyResistance = 0.2f;
    bool criticalHit = true;

    int preDamage = preCastModifiers(spellbook["Fireball"], intelligence, spellPowerBoost);
    int finalDamage = postCastEffects(preDamage, enemyResistance, criticalHit);

    std::cout << "\nCasting Fireball...\n";
    std::cout << "Damage after pre-cast modifiers: " << preDamage << "\n";
    std::cout << "Final damage after post-cast effects: " << finalDamage << "\n";

    return 0;
}
