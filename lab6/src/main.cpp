//
// Created by anon on 11/15/21.
//


#include <iostream>
#include "Vector.h"
#include "Imaginary.h"

using namespace std;


int main() {
    Vector v1(7, 3);
    Vector v2(4, 2);

    v1 += v2;
    v1.print();
    Vector v3 = v1 * 0.5;
    v3.print();
    Vector v4 = v3;
    v4.print();

    if (v1 > v3) {cout << "Tak!";}
    if (v1 < v3) {cout << "Nie!";}
    return 0;
}