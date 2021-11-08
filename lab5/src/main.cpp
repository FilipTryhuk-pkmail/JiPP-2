//
// Created by anon on 11/8/21.
//

#include <iostream>
#include "Pojazd.h"

using namespace std;

int main() {
    string crew[6];
    crew[0] = "Siege";
    crew[1] = "Peasant1";
    crew[2] = "Peasant2";
    crew[3] = "Peasant3";
    crew[4] = "Lookout";
    crew[5] = "Horses";
    Pojazd trebuchet(30090, "CastleBane", 6, "M6", crew);
    trebuchet.printout();
    cout << endl;
    trebuchet.printPassenger(2);

    Pojazd treb2 = trebuchet;



    return 0;
}