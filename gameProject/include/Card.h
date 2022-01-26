//
// Created by anon on 1/23/22.
//

#ifndef JIPP_2_CARD_H
#define JIPP_2_CARD_H

#include <iostream>
#include <vector>

using namespace std;

class Card {
protected:
    string name;
    double power;
    double life_max;
    double life_cur;
public:
    /**
     * Card constructor for the Card base class, evoked by the child classes
     * @param name Name of the created card
     * @param power Power of the created card
     * @param life_max Maximum health of the created card
     */
    Card(string name, double power, double life_max);

    /**
     * Getter for the power field double
     * @return power of the Card
     */
    double getPower();

    /**
     * Getter for the life_max double
     * @return life_max of the Card
     */
    double getMaxLife();

    /**
     * Getter for the life_cur double
     * @return life_cur of the Card
     */
    double getCurrentLife();

    /**
     * Getter for the name string
     * @return name of the Card
     */
    string getName();

    /**
     * function stub for combat calculations, to be overridden by the child classes
     * @param damage damage to be dealt to the Card, before defense calculations
     */
    static void takeDamage(double damage);
    bool alive = true;

    ~Card() = default;
};

#endif //JIPP_2_CARD_H


