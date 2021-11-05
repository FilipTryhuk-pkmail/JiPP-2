//
// Created by anon on 11/5/21.
//

#ifndef JIPP_2_FIGURA_H
#define JIPP_2_FIGURA_H
#include "Punkt.h"


class Figura {
public:
    int vertexCount;
    Punkt *vArray = new Punkt[vertexCount];
    Figura(int vertexCount, Punkt *vArray);
};


#endif //JIPP_2_FIGURA_H
