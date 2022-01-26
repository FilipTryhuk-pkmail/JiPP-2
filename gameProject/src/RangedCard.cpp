//
// Created by anon on 1/24/22.
//

#include <RangedCard.h>

#include <utility>

struct ClassException : public exception {
    const char *what() const noexcept {
        return "Can't set armor to non-melee units!";
    }
};

void RangedCard::takeDamage(double damage) {
    if (unusedDodge and (rand()%100 < dodgeChance)) {
        damage = 0;
        unusedDodge = false;
        cout << name << " successfully dodged the incoming attack!" << endl;
    }
    life_cur -= damage;
    if (life_cur < 1) {
        alive = false;
    }
}

void RangedCard::takeDamage(double damage, double true_damage_percent) {
    if (unusedDodge and (rand()%100 < dodgeChance)) {
        damage = 0;
        true_damage_percent = 0;
        unusedDodge = false;
        cout << name << " successfully dodged the incoming attack!" << endl;
    }
    life_cur *= (1.0 - true_damage_percent);
    life_cur -= damage;
    if (life_cur < 1) {
        alive = false;
    }
}

RangedCard::RangedCard(string name, double power, double life_max) : Card(std::move(name), power, life_max) {
    dodgeChance = 50;
}

RangedCard::RangedCard(string name, double power, double life_max, int dodgeChance) : Card(std::move(name), power, life_max), dodgeChance(dodgeChance) {
    if (dodgeChance > 100) dodgeChance = 100;
}

void RangedCard::setArmor(int newArmor) {
    throw ClassException();
}

