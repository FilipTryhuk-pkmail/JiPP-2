//
// Created by anon on 11/8/21.
//

#ifndef JIPP_2_POJAZD_H
#define JIPP_2_POJAZD_H

#include <string>

using namespace std;

class Pojazd {
private:
    int plate;
    string name;
    int pass_count;
    string model;
    string *pass = new string[pass_count];

public:
    Pojazd(int plate, string name, int pass_count, string model, string *pass);
    Pojazd(Pojazd &pojazd);
    void printout();
    void printPassenger(int slot);
};


#endif //JIPP_2_POJAZD_H
