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
    /**
     * Card constructor for the RangedCard class, using only Card params
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     */
    RangedCard(string name, double power, double life_max);

    /**
     * Card constructor for the RangedCard class, using Card params and a dodgeChance param
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     * @param dodgeChance Chance (in percentage points) for the created card to avoid an incoming attack
     */
    RangedCard(string name, double power, double life_max, int dodgeChance);

    /**
     * Processes incoming physical damage and sets the alive flag if necessary
     * @param damage Damage amount if the attack wasn't avoided
     */
    void takeDamage(double damage);

    /**
     * Processes incoming magical damage and sets the alive flag if necessary
     * @param damage Damage amount if the attack wasn't avoided
     * @param true_damage_percent Fraction of max_life to be removed if the attack wasn't avoided
     */
    void takeDamage(double damage, double true_damage_percent);

    /**
     * Raises an exception when trying to set armor field of an RangedCard object
     * @param newArmor new armor value, ignored by this function
     */
    static void setArmor(int newArmor);
};

#endif //JIPP_2_RANGEDCARD_H
