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

    /**
     * Card constructor for the MeleeCard class, using only Card params
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     */
    MeleeCard(string name, double power, double life_max);

    /**
     * Card constructor for the MeleeCard class, using Card params and an armor param
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     * @param armor Armor of the created card
     */
    MeleeCard(string name, double power, double life_max, int armor);

    /**
     * Processes incoming physical damage and sets the alive flag if necessary
     * @param damage Damage amount before defense calculations
     */
    void takeDamage(double damage);

    /**
     * Processes incoming magical damage and sets the alive flag if necessary
     * @param damage Damage amount before defense calculations
     * @param true_damage_percent Fraction of max_life to be removed regardless of armor
     */
    void takeDamage(double damage, double true_damage_percent);

    /**
     * Setter for the armor field of the MeleeCard object
     * @param newArmor New armor amount
     */
    void setArmor(int newArmor);

    /**
     * Overloaded + operator adding together power, life_max and armor of two MeleeCards
     * @param rhs MeleeCard to be added to the object calling the function
     * @return MeleeCard params set
     */
    MeleeCard operator+(const MeleeCard &rhs) const;
};

#endif //JIPP_2_MELEECARD_H


