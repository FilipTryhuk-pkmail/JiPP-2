//
// Created by anon on 11/15/21.
//

#include "Imaginary.h"
#include <iostream>

Imaginary::Imaginary() {
    real = 0;
    imag = 0;
}

Imaginary::Imaginary(double real, double imag) : real(real), imag(imag) {}

void Imaginary::print() {
    cout << "liczba ma postac: (" << real << ") + (" << imag << ")i" << endl;
}

Imaginary Imaginary::operator+(const Imaginary &rhs) {
    return {real + rhs.real, imag + rhs.imag};
}
Imaginary Imaginary::operator-(const Imaginary &rhs) {
    return {real - rhs.real, imag - rhs.imag};
}
double Imaginary::operator*(const Imaginary &rhs) {
    return (real * rhs.real - imag * rhs.imag);
}
double Imaginary::operator/(const Imaginary &rhs) {
    double (real / rhs.real + imag / rhs.imag);
}


