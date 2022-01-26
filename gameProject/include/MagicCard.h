//
// Created by anon on 1/24/22.
//

#ifndef JIPP_2_MAGICCARD_H
#define JIPP_2_MAGICCARD_H

#include <iostream>
#include "Card.h"

using namespace std;

class MagicCard: public Card{
private:
    double ethereal;
public:
    double true_damage_dealt;
    MagicCard(string name, double power, double life_max);
    MagicCard(string name, double power, double life_max, double ethereal, double true_damage_dealt);
    void takeDamage(double damage);
    void takeDamage(double damage, double true_damage_percent);
    static void setArmor(int newArmor);
};


#endif //JIPP_2_MAGICCARD_H

