//
// Created by anon on 1/23/22.
//

#include <Card.h>
#include <exception>
#include <utility>

struct AttackException : public exception {
    const char *what() const noexcept {
        return "Base Class 'Card' should never engage in combat!";
    }
};

double Card::getPower() {
    return power;
}

double Card::getMaxLife() {
    return life_max;
}

double Card::getCurrentLife() {
    return life_cur;
}

void Card::takeDamage(double damage) {
    throw AttackException();
}

Card::Card(string name, double power, double life_max) : name(std::move(name)), power(power), life_max(life_max) {
    life_cur = life_max;
}

string Card::getName() {
    return name;
}


