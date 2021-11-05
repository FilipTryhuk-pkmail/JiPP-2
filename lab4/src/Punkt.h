//
// Created by anon on 11/5/21.
//

#ifndef JIPP_2_PUNKT_H
#define JIPP_2_PUNKT_H

using namespace std;

class Punkt {
public:
    double xPos;
    double yPos;
    Punkt(double xPos, double yPos);
    Punkt();
    double distance(Punkt start, Punkt end);
    double getXPos();
    double getYPos();
};


#endif //JIPP_2_PUNKT_H
