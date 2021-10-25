//
// Created by anon on 10/25/21.
//

#ifndef JIPP_2_CUBOID_H
#define JIPP_2_CUBOID_H
#include <iostream>


class Cuboid {
private:
    unsigned int length;
    unsigned int width;
    unsigned int height;
public:
    Cuboid(unsigned int length, unsigned int width, unsigned int height);

    double calculateVolume();
};


#endif //JIPP_2_CUBOID_H
