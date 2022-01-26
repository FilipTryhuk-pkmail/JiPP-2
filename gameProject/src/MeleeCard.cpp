//
// Created by anon on 1/23/22.
//

#include <MeleeCard.h>

#include <utility>


void MeleeCard::takeDamage(double damage) {
    if (damage - armor > 0) {
        life_cur -= (damage - armor);
    } else {
        cout << name << "'s armor fully resisted the attack!" << endl;
    }
    if (life_cur < 1) {
        alive = false;
    }
}

void MeleeCard::takeDamage(double damage, double true_damage_percent) {
    life_cur *= (1.0 - true_damage_percent);
    cout << "The elemental attack goes right through " << name << "'s armor!" << endl;
    if (damage - armor > 0) {
        life_cur -= (damage - armor);
    }
    if (life_cur < 1) {
        alive = false;
    }
}

MeleeCard::MeleeCard(string name, double power, double life_max) : Card(std::move(name), power, life_max) {
    armor = 100;
}

MeleeCard::MeleeCard(string name, double power, double life_max, int armor) : Card(std::move(name), power, life_max), armor(armor) {
}

void MeleeCard::setArmor(int newArmor) {
    armor = newArmor;
}
