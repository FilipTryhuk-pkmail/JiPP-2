//
// Created by anon on 10/25/21.
//

#include "Sphere.h"
#define PI 3.14

Sphere::Sphere(unsigned int radius) {
    this->radius = radius;
}

double Sphere::calculateVolume() {
    double volume = (4/3.) * PI;
    volume *= radius * radius * radius;
    return volume;
}
