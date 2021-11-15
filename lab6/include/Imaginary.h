//
// Created by anon on 11/15/21.
//

#ifndef JIPP_2_IMAGINARY_H
#define JIPP_2_IMAGINARY_H

#include <string>
#include <valarray>

using namespace std;

class Imaginary {
private:
    double real;
    double imag;
public:
    Imaginary();
    Imaginary(double real, double imag);
    void print();
    Imaginary operator+(const Imaginary &rhs);
    Imaginary operator-(const Imaginary &rhs);
    double operator*(const Imaginary &rhs);
    double operator/(const Imaginary &rhs);
};


#endif //JIPP_2_IMAGINARY_H
