//
// Created by anon on 11/8/21.
//

#include <iostream>
#include "Pojazd.h"

using namespace std;

double Pojazd::newestSoftwareVer = 1.0;

int main() {
    string crew[6];
    crew[0] = "Siege";
    crew[1] = "Peasant1";
    crew[2] = "Peasant2";
    crew[3] = "Peasant3";
    crew[4] = "Lookout";
    crew[5] = "Horses";
    Pojazd trebuchet(30090, "CastleBane", 6, "M6", crew, 0.8);
    trebuchet.printout();
    cout << endl;
    trebuchet.printPassenger(2);

    Pojazd treb2 = trebuchet;
    cout << endl << treb2.getCurrentSoftwareVer() << endl;
    treb2.updateSoftware();
    cout << treb2.getCurrentSoftwareVer() << endl;
    Pojazd::releaseSoftwareUpdate(1.2);
    treb2.updateSoftware();
    cout << treb2.getCurrentSoftwareVer() << endl;

    return 0;
}