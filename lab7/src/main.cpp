//
// Created by anon on 11/22/21.
//
#include <iostream>
#include <cmath>

using namespace std;
double PI = 3.14159265359;

class Figure {
protected:
    const string name;
    const string color;
public:
    Figure(const string &name, const string &color): name(name), color(color) {}
    Figure() {}
    virtual double getCircumference() = 0;
    virtual double getArea() = 0;
};

class Rectangle: public Figure {
protected:
    unsigned int a;
    unsigned int b;
public:
    Rectangle(const string &name, const string &color, unsigned int a, unsigned int b): Figure(name, color), a(a), b(b) {}
    Rectangle(unsigned int a, unsigned int b): a(a), b(b) {}
    double getCircumference() {
        return (2*a + 2*b);
    }
    double getArea() {
        return (a*b);
    }
};

class EquilateralTriangle: public Figure {
protected:
    unsigned int a;
public:
    EquilateralTriangle(const string &name, const string &color, unsigned int a): Figure(name, color), a(a) {}
    EquilateralTriangle(unsigned int a): a(a) {}
    double getCircumference() {
        return (3*a);
    }
    double getArea() {
        return ((a*a*sqrt(3)) / 2);
    }
};

class Circle: public Figure {
protected:
    unsigned int r;
public:
    Circle(const string &name, const string &color, unsigned int r): Figure(name, color), r(r) {}
    Circle(unsigned int r): r(r) {}
    double getCircumference() {
        return (PI * 2 * r);
    }
    double getArea() {
        return (4/3. * PI * r * r);
    }

};

void zad7() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
}






int main() {
//    zad7();



    return 0;
}
