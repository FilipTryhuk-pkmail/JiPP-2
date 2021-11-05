//
// Created by anon on 11/5/21.
//

#include "FunkcjaKwadratowa.h"


FunkcjaKwadratowa::FunkcjaKwadratowa(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void FunkcjaKwadratowa::displayFunc() {
    cout << "f(x) = " << a << " x^2 + " << b << " x + " << c << endl;
}

unsigned int FunkcjaKwadratowa::getA() {
    return a;
}
unsigned int FunkcjaKwadratowa::getB() {
    return b;
}
unsigned int FunkcjaKwadratowa::getC() {
    return c;
}

void FunkcjaKwadratowa::setA(unsigned int a) {
    this->a = a;
}

void FunkcjaKwadratowa::setB(unsigned int b) {
    this->b = b;
}

void FunkcjaKwadratowa::setC(unsigned int c) {
    this->c = c;
}
