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
    static double newestSoftwareVer;
    double currentSoftwareVer;

public:
    Pojazd(int plate, string name, int pass_count, string model, string *pass, double currentSoftwareVer);
    Pojazd(Pojazd &pojazd);
    void printout();
    void printPassenger(int slot);
    string getName() const;
    int getPlate() const;
    string getModel() const;
    void setName(string name);
    void setPlate(int plate);
    double getCurrentSoftwareVer() const;
    void updateSoftware();
    static void releaseSoftwareUpdate(double update);
};


#endif //JIPP_2_POJAZD_H
