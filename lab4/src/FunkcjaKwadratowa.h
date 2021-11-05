//
// Created by anon on 11/5/21.
//

#ifndef JIPP_2_FUNKCJAKWADRATOWA_H
#define JIPP_2_FUNKCJAKWADRATOWA_H
#include <iostream>
#include <string>



using namespace std;

class FunkcjaKwadratowa {
private:
    unsigned int a;
    unsigned int b;
    unsigned int c;
public:
    FunkcjaKwadratowa(int a, int b, int c);
    void displayFunc();
    unsigned int getA();
    unsigned int getB();
    unsigned int getC();
    void setA(unsigned int a);
    void setB(unsigned int b);
    void setC(unsigned int c);
};


#endif //JIPP_2_FUNKCJAKWADRATOWA_H


