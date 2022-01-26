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

    /**
     * Card constructor for the MagicCard class, using only Card params
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     */
    MagicCard(string name, double power, double life_max);

    /**
     * Card constructor for the MagicCard class, using Card params and two MagicCard specific params
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     * @param ethereal Magic armor of the created card, reduces non-magical damage by a set fraction
     * @param true_damage_dealt Magic damage dealt by the created card, removes a fraction of the defender's max_life on attack
     */
    MagicCard(string name, double power, double life_max, double ethereal, double true_damage_dealt);

    /**
     * Processes incoming physical damage and sets the alive flag if necessary
     * @param damage Damage amount before applying the reduction from this card's ethereal stat
     */
    void takeDamage(double damage);

    /**
     * Processes incoming magical damage and sets the alive flag if necessary
     * @param damage Damage amount before defense calculation
     * @param true_damage_percent Fraction of max_life to be removed before defense calculation
     */
    void takeDamage(double damage, double true_damage_percent);

    /**
     * Raises an exception when trying to set armor field of an MagicCard object
     * @param newArmor new armor value, ignored by this function
     */
    static void setArmor(int newArmor);
};


#endif //JIPP_2_MAGICCARD_H

