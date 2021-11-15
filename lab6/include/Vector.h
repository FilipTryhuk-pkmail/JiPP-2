//
// Created by anon on 11/15/21.
//

#ifndef JIPP_2_VECTOR_H
#define JIPP_2_VECTOR_H


#include <string>
#include <valarray>

using namespace std;

class Vector{
private:
    double x, y;

public:
    Vector();
    Vector(double x, double y);

    double length() const;
    Vector operator+(const Vector &rhs);
    Vector operator-(const Vector &rhs);
    Vector &operator+=(const Vector &rhs);
    double operator*(const Vector &rhs);
    Vector operator*(const double &rhs);
    bool operator>(const Vector &rhs);
    bool operator<(const Vector &rhs);
    Vector &operator=(const Vector &rhs);
    void print() const;
};

#endif //JIPP_2_VECTOR_H
