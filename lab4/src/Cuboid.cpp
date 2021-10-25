//
// Created by anon on 10/25/21.
//

#include "Cuboid.h"

Cuboid::Cuboid(unsigned int length, unsigned int width, unsigned int height) {
    this->length = length;
    this->width = width;
    this->height = height;
}

double Cuboid::calculateVolume() {
    double volume = 1.;
    volume *= (length * width * height);
    return volume;
}
