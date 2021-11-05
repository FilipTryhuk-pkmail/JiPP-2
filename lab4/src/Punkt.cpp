//
// Created by anon on 11/5/21.
//

#include <valarray>
#include "Punkt.h"

Punkt::Punkt(double xPos, double yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
}

double Punkt::distance(Punkt start, Punkt end) {
    double dist;
    dist = (end.xPos - start.xPos)*(end.xPos - start.xPos) + (end.yPos - start.yPos)*(end.yPos - start.yPos);
    dist = sqrt(dist);
    return dist;
}

Punkt::Punkt() {
    xPos = 0;
    yPos = 0;
}

double Punkt::getXPos() {
    return xPos;
}

double Punkt::getYPos() {
    return yPos;
}
