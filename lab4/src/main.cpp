//
// Created by anon on 10/25/21.
//

#include <iostream>
#include <string>
#include "Cuboid.h"
#include "Sphere.h"
#include "FunkcjaKwadratowa.h"
#include "Student.h"
#include "Punkt.h"
#include "Figura.h"

using namespace std;

struct samochod{
    string brand;
    string model;
    string color;
    int year_of_production;
};

int main(int argc, char *argv[]) {

    //STRUKTURY
    samochod cars[] = {{"Opel",  "OP1",  "black",  2018},
                       {"Skoda", "SK2",  "red",    2016},
                       {"BMW",   "BMW3", "black",  2013},
                       {"Opel",  "OP2",  "silver", 2015},};

    for (int i = 0; i < 4; i++)
    {
        cout << cars[i].brand << "\t\t" << cars[i].model << "\t\t" << cars[i].color << "\t\t" << cars[i].year_of_production << endl;
    }


    //KLASY
    Cuboid bryla(4, 6, 5);
    cout << endl << "Objętość graniastosłupa: " << bryla.calculateVolume() << endl;

    Sphere kula(5);
    cout << endl << "Objętość kuli: " << kula.calculateVolume() << endl << endl;

    FunkcjaKwadratowa func(1, 2, 4);
    func.displayFunc();

    Student abc("Jan", "Kowalski", 366521, 20, 13);
    cout << endl << "Student udzielił " << abc.calculateCorrect() << "% poprawnych odpowiedzi." << endl;

    Punkt x1(3, 2);
    Punkt x2(9,7);

    cout << endl << "Distance between the points is equal to: " << x1.distance(x1, x2) << endl;

    Punkt wierzch[3];
    wierzch[0] = Punkt(5,1);
    wierzch[1] = Punkt(1,5);
    wierzch[2] = Punkt(3, 3);

    Figura fig1(3, wierzch);
    cout << endl << fig1.vArray[2].yPos << endl;
    return 0;
}