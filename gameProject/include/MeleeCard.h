//
// Created by anon on 1/23/22.
//

#ifndef JIPP_2_MELEECARD_H
#define JIPP_2_MELEECARD_H

#include <iostream>
#include "Card.h"

using namespace std;

class MeleeCard: public Card{
private:
    int armor;
public:
    MeleeCard(string name, double power, double life_max);
    MeleeCard(string name, double power, double life_max, int armor);
    void takeDamage(double damage);
    void takeDamage(double damage, double true_damage_percent);
    void setArmor(int newArmor);
    MeleeCard operator+(const MeleeCard &rhs) const;
};

#endif //JIPP_2_MELEECARD_H


