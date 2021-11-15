//
// Created by anon on 11/15/21.
//

#include "Vector.h"
#include <iostream>

Vector::Vector(){
    x = 0;
    y = 0;
};

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::length() const {
        return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &rhs) {
    return {x + rhs.x, y + rhs.y};
}

Vector &Vector::operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
}

void Vector::print() const {
    cout << "Wektor znajudje sie: x=" << x << ", y=" << y << endl;
}

double Vector::operator*(const Vector &rhs) {
    return (x * rhs.x + y * rhs.y);
}

Vector Vector::operator*(const double &rhs) {
    return {x * rhs, y * rhs};
}

Vector Vector::operator-(const Vector &rhs) {
    return {x - rhs.x, y - rhs.y};
}

bool Vector::operator>(const Vector &rhs) {
    if (this->length() > rhs.length()) {return true;}
    else return false;
}

bool Vector::operator<(const Vector &rhs) {
    if (this->length() < rhs.length()) {return true;}
    else return false;
}

Vector &Vector::operator=(const Vector &rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}