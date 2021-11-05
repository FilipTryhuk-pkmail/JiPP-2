//
// Created by anon on 11/5/21.
//

#include "Figura.h"

Figura::Figura(int vertexCount, Punkt *vArray) {
    this->vertexCount = vertexCount;
    for(int i=0; i<vertexCount; i++) {
        this->vArray[i] = vArray[i];
    }

}
