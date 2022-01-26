//
// Created by anon on 1/24/22.
//

#ifndef JIPP_2_RANGEDCARD_H
#define JIPP_2_RANGEDCARD_H

#include <iostream>
#include "Card.h"

using namespace std;

class RangedCard: public Card{
private:
    bool unusedDodge = true;
    int dodgeChance;
public:
    RangedCard(string name, double power, double life_max);
    RangedCard(string name, double power, double life_max, int dodgeChance);
    void takeDamage(double damage);
    void takeDamage(double damage, double true_damage_percent);
    static void setArmor(int newArmor);
};

#endif //JIPP_2_RANGEDCARD_H
