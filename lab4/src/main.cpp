//
// Created by anon on 10/25/21.
//

#include <iostream>
#include <string>
#include "Cuboid.h"

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

    return 0;
}