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
    int kill_count = 0;
public:
    Card(string name, double power, double life_max);
    double getPower();
    double getMaxLife();
    double getCurrentLife();
    string getName();
    static void takeDamage(double damage);
    bool alive = true;
    Card &operator+=(const Card &rhs);

};

#endif //JIPP_2_CARD_H


