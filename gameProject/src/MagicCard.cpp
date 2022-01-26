//
// Created by anon on 1/24/22.
//

#include <MagicCard.h>

#include <utility>

struct ClassException : public exception {
    const char *what() const noexcept {
        return "Can't set armor to non-melee units!";
    }
};

void MagicCard::takeDamage(double damage) {
    life_cur -= damage * (1 - ethereal);
    if (life_cur < 1) {
        alive = false;
    }
}

void MagicCard::takeDamage(double damage, double true_damage_percent) {
    if (ethereal > true_damage_percent) {
        life_cur -= damage;
        cout << name << "'s magical shield was momentarily disrupted by the arcane attack!" << endl;
    } else {
        life_cur *= (1.0 - (true_damage_percent - ethereal));
        life_cur -= damage;
    }
    if (life_cur < 1) {
        alive = false;
    }
}

MagicCard::MagicCard(string name, double power, double life_max) : Card(std::move(name), power, life_max) {
    ethereal = 0.5;
    true_damage_dealt = 0.2;
}

MagicCard::MagicCard(string name, double power, double life_max, double ethereal, double true_damage_dealt) : Card(std::move(name), power, life_max), ethereal(ethereal), true_damage_dealt(true_damage_dealt) {
    if (ethereal > 1) ethereal = 1;
    if (true_damage_dealt > 1) true_damage_dealt = 1;
}

void MagicCard::setArmor(int newArmor) {
    throw ClassException();
}